#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int Parent[1001];

int Find(int id)
{
	if (Parent[id] == id)
	{
		return id;
	}

	return Parent[id] = Find(Parent[id]);
}

void Union(int a, int b)
{
	int A = Find(a);
	int B = Find(b);

	if (A == B)
		return;
	
	Parent[A] = B;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i <= N; ++i)
	{
		Parent[i] = i;
	}

	priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> pq;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int weight;
			cin >> weight;
			pq.push({ weight,i,j });
		}
	}
	
	ll output = 0;
	while (!pq.empty())
	{
		auto X = pq.top(); pq.pop();
		int weight = get<0>(X);
		int st = get<1>(X);
		int ed = get<2>(X);

		if (Find(st) == Find(ed))
			continue;

		Union(st, ed);
		output += weight;
	}

	cout << output;

	return 0;
}