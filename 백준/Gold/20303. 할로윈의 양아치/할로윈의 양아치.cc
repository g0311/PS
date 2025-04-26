#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<int> cnd;
vector<int> friends[30001];
int visited[30001];
vector<pair<int, int>> blocks;
		//candy, children

int DP[30001];

bool Comp(pair<int, int> a, pair<int, int> b)
{
	float aX = (float)a.first / a.second;
	float bX = (float)b.first / b.second;
	return aX > bX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	cnd.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> cnd[i];
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
			continue;
		int curId = blocks.size();
		blocks.push_back({ 0,0 });
		queue<int> q;
		q.push(i);
		visited[i] = 1;
		blocks[curId].first += cnd[i];
		blocks[curId].second++;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int j = 0; j < friends[cur].size(); j++)
			{
				if (visited[friends[cur][j]])
					continue;
				q.push(friends[cur][j]);
				visited[friends[cur][j]] = 1;
				blocks[curId].first += cnd[friends[cur][j]];
				blocks[curId].second++;
			}
		}
	}
	for (auto block : blocks) 
	{
		int candy = block.first;
		int size = block.second;
		for (int i = K - 1; i >= size; i--) 
		{
			DP[i] = max(DP[i], DP[i - size] + candy);
		}
	}
	cout << DP[K - 1];

	return 0;
}