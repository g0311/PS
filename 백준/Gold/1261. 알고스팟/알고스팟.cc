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

int M, N;
vector<string>Map;
int Visited[100][100];
int output = INF;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void Solve_(int x, int y, int ct)
{
	if (ct > output)
		return;
	if (x == M - 1 && y == N - 1)
	{
		output = min(output, ct);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (Visited[ny][nx] == 1)
			continue;
		Visited[ny][nx] = 1;
		if (Map[ny][nx] == '1')
			Solve_(nx, ny, ct + 1);
		else
			Solve_(nx, ny, ct);
		Visited[ny][nx] = 0;
	}
}

void Solve()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {0, 0} });
	while (!pq.empty())
	{
		int ct = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if(y == N -1 && x == M - 1)
		{
			output = min(output, -ct);
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (Visited[ny][nx] == 1)
				continue;
			Visited[ny][nx] = 1;
			if (Map[ny][nx] == '1')
			{
				pq.push({ -(ct + 1),{ny, nx} });
			}
			else
			{
				pq.push({ -ct,{ny, nx} });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	Map.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}
	Solve();
	cout << -output;

	return 0;
}
//100'000