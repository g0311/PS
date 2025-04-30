
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000

int parent[4'000'001];

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	if (Find(a) == Find(b))
		return;
	parent[Find(a)] = Find(b);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	vector<int> minsu(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> minsu[i];
	}

	sort(minsu.begin(), minsu.end());
	for (int i = 0; i < K; i++)
	{
		int chulsu;
		cin >> chulsu;
		auto out = upper_bound(minsu.begin(), minsu.end(), chulsu);
		if (out == minsu.end())
		{
			out--;
		}
		int d = Find(*out);
		cout << d << endl;
		Union(d, d + 1);
	}

	return 0;
}
