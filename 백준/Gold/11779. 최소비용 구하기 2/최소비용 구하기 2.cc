#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

vector<pair<int, int>> Map[1001];
int dist[1001];
int path[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Map[a].push_back({ b, c });
	}
	int st, ed;
	cin >> st >> ed;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[st] = 0;
	path[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		
		for (int i = 0; i < Map[cur].size(); i++)
		{
			int next = Map[cur][i].first;
			int nextCost = Map[cur][i].second + cost;
			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
				path[next] = cur;
			}
		}
	}
	cout << dist[ed] << endl;
	vector<int> pathVec;
	pathVec.push_back(ed);
	while (path[ed] != 0)
	{
		pathVec.push_back(path[ed]);
		ed = path[ed];
	}
	cout << pathVec.size() << endl;
	for (int i = pathVec.size() - 1; i >= 0; i--)
	{
		cout << pathVec[i] << " ";
	}

	return 0;
}
