#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

#define OUT

int V, E;
vector<pii> Map[10001];
map<ll, vector<ll>> mimMap;

void Dijkstra(int start, OUT vector<ll>& out)
{
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({ 0, start });
	out[start] = 0;
	while (!pq.empty())
	{
		int curPos = pq.top().second;
		int curW = pq.top().first;
		pq.pop();

		if (out[curPos] < curW)
			continue;

		for (int i = 0; i < Map[curPos].size(); ++i)
		{
			int nexPos = Map[curPos][i].first;
			int newW = Map[curPos][i].second;

			int totalW = curW + newW;
			if (out[nexPos] <= totalW)
				continue;

			out[nexPos] = totalW;
			pq.push({ totalW, nexPos });
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		Map[u].push_back({ v, w });
		Map[v].push_back({ u, w });
	}

	vector<int> maamPos(10,0);
	for (int i = 0; i < 10; ++i)
	{
		cin >> maamPos[i];
		if(mimMap.find(maamPos[i]) == mimMap.end())
		{
			mimMap[maamPos[i]].resize(V + 1,LLMAX);
			Dijkstra(maamPos[i], mimMap[maamPos[i]]);
		}
	}

	int playerPos;
	cin >> playerPos;
	if (mimMap.find(playerPos) == mimMap.end())
	{
		mimMap[playerPos].resize(V + 1, LLMAX);
		Dijkstra(playerPos, mimMap[playerPos]);
	}
	vector<int> Out;
	
	int maamCurPos = maamPos[0];
	ll curWeight = 0;
	for (int i = 0; i < 9; i++)
	{
		if (mimMap[playerPos][maamCurPos] <= curWeight)
		{
			Out.push_back(maamCurPos);
		}

		if (mimMap[maamCurPos][maamPos[i + 1]] == LLMAX)
		{
			i++;
		}
		else
		{
			curWeight += mimMap[maamCurPos][maamPos[i + 1]];
			maamCurPos = maamPos[i + 1];
		}
	}
	if (mimMap[playerPos][maamCurPos] <= curWeight)
	{
		Out.push_back(maamCurPos);
	}

	sort(Out.begin(), Out.end());
	if (Out.empty())
		cout << -1 << endl;
	else
		cout << Out[0];

	return 0;
}