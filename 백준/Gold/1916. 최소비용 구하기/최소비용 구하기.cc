#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> Map(N + 1);
	for (int i = 0; i < M; i++)
	{
		int st, ed, w;
		cin >> st >> ed >> w;
		Map[st].push_back({ w, ed });
	}
	int st, ed;
	cin >> st >> ed;

	vector<int> dist(N + 1, INF);
	dist[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (int i = 0; i < Map[curNode].size(); i++)
		{
			int nextNode = Map[curNode][i].second;
			int nextDist = curDist + Map[curNode][i].first;
			if (dist[nextNode] > nextDist)
			{
				dist[nextNode] = nextDist;
				pq.push({ nextDist, nextNode });
			}
		}
	}
	cout << dist[ed] << endl;

	return 0;
}