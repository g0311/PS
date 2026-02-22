#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, P;
	cin >> V >> E >> P;
	vector<vector<pii>> Map(V + 1);
	
	for (int i = 0; i < E; ++i)
	{
		int st, ed, w;
		cin >> st >> ed >> w;
		Map[st].push_back({ w,ed });
		Map[ed].push_back({ w,st });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> Visited(V + 1, INF);
	pq.push({ 0,1 });
	Visited[1] = 0;
	while (!pq.empty())
	{
		int curPos = pq.top().second;
		int curWeight = pq.top().first;
		pq.pop();

		for (int i = 0; i < Map[curPos].size(); ++i)
		{
			int nextWeight = curWeight + Map[curPos][i].first;
			int nextPos = Map[curPos][i].second;
			if (Visited[nextPos] > nextWeight)
			{
				Visited[Map[curPos][i].second] = nextWeight;
				pq.push({ nextWeight , nextPos });
			}
		}
	}
	int target = Visited[V];
	int toHim = Visited[P];

	Visited.assign(V + 1, INF);
	pq.push({ 0,P });
	Visited[P] = 0;
	while (!pq.empty())
	{
		int curPos = pq.top().second;
		int curWeight = pq.top().first;
		pq.pop();

		for (int i = 0; i < Map[curPos].size(); ++i)
		{
			int nextWeight = curWeight + Map[curPos][i].first;
			int nextPos = Map[curPos][i].second;
			if (Visited[nextPos] > nextWeight)
			{
				Visited[Map[curPos][i].second] = nextWeight;
				pq.push({ nextWeight , nextPos });
			}
		}
	}
	int himToMasan = Visited[V];

	if (target == toHim + himToMasan)
	{
		cout << "SAVE HIM" << endl;
	}
	else
	{
		cout << "GOOD BYE" << endl;
	}

	return 0;
}

// st -> ed == st -> target -> ed 이면 pass