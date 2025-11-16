#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

int Parent[100001];

int Find(int a)
{
	if (Parent[a] == a)
		return a;
	else
		return Parent[a] = Find(Parent[a]);
}

void Union(int a, int b)
{
	int A = Find(a);
	int B = Find(b);

	if (A == B)
		return;
	else
		Parent[A] = B;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; ++i)
		Parent[i] = i;

	vector<tuple<int, int, int>> edges;
	ll Sum = 0;
	for (int i = 0; i < M; ++i)
	{
		int st, ed, cost;
		cin >> st >> ed >> cost;
		edges.push_back({ cost,st,ed });
		Sum += cost;
	}
	sort(edges.begin(), edges.end());

	ll out = 0;
	int ct = 0;
	for (auto edge : edges)
	{
		int cost = get<0>(edge);
		int st = get<1>(edge);
		int ed = get<2>(edge);

		if (Find(st) == Find(ed))
			continue;

		Union(st, ed);
		out += cost;
		ct++;
	}

	if (ct != N - 1)
	{
		cout << -1;
		return 0;
	}

	cout << Sum - out;

	return 0;
}