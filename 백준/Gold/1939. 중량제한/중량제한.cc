#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

vector<map<int, int>> Map;
ll DP[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	Map.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (Map[a].find(b) == Map[a].end() || Map[a][b] < c)
		{
			Map[a][b] = c;
		}
		if (Map[b].find(a) == Map[b].end() || Map[b][a] < c)
		{
			Map[b][a] = c;
		}
	}

	int st, ed;
	cin >> st >> ed;

	queue<pair<int, int>> q;
	q.push({ st, INF });
	DP[st] = INF;
	while (!q.empty())
	{
		int cur = q.front().first;
		ll curCost = q.front().second;
		q.pop();

		if (DP[cur] > curCost) continue;

		for (auto& next : Map[cur])
		{
			int nextNode = next.first;
			ll cost = next.second;

			ll nextCost = min(curCost, cost);
			if (nextCost <= DP[nextNode]) continue;
			
			DP[nextNode] = nextCost;
			q.push({ nextNode, nextCost });
		}
	}

	cout << DP[ed] << endl;

	return 0;
}