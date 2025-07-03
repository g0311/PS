#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e10

vector<tuple<int,int,int>> grp;
ll Dist[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		grp.push_back({ u,v,w });
	}
	for (int i = 0; i <= N; i++)
	{
		Dist[i] = INF;
	}

	Dist[1] = 0;
	for (int i = 1; i < N; i++)
	{
		for (auto [u, v, w] : grp)
		{
			if (Dist[u] != INF && Dist[v] > Dist[u] + w)
			{
				Dist[v] = Dist[u] + w;
			}
		}
	}

	for (auto [u, v, w] : grp)
	{
		if (Dist[u] != INF && Dist[v] > Dist[u] + w)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (Dist[i] == INF)
			cout << -1 << endl;
		else
			cout << Dist[i] << endl;
	}

	return 0;
}