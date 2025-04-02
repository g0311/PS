#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

vector<pair<int, int>> edges[5000];
int dist[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ c,b });
		edges[b].push_back({ c,a });
	}
	int s, t;
	cin >> s >> t;

	for (int i = 0; i <= n; i++)
	{
		dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curVer = pq.top().second;
		pq.pop();

		if (dist[curVer] < curDist)
			continue;

		dist[curVer] = curDist;
		
		for (int i = 0; i < edges[curVer].size(); i++)
		{
			int nexVer = edges[curVer][i].second;
			int nexDist = edges[curVer][i].first;
			if (dist[nexVer] > nexDist + curDist)
			{
				pq.push({ nexDist + curDist, nexVer });
			}
		}
	}
	
	cout << dist[t];
	return 0;
}