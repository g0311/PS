#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int Map[200][200];
int Visited[200][200][31];

int dx1[] = { 0, 0, 1, -1 };
int dy1[] = { 1, -1, 0, 0 };
int dx2[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy2[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k, n, m;
	cin >> k >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}

	if (Map[0][0] == 1 || Map[n - 1][m - 1] == 1) 
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			for (int l = 0; l <= k; l++) 
			{
				Visited[i][j][l] = INF;
			}
		}
	}

	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 0, k });
	Visited[0][0][k] = 0;

	int output = INF;

	while (!q.empty())
	{
		auto [cost, y, x, curK] = q.front();
		q.pop();

		if (cost > Visited[y][x][curK])
		{
			continue;
		}

		if (y == n - 1 && x == m - 1) 
		{
			output = min(output, cost);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			int nexCost = cost + 1;
			int nexK = curK;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (Map[ny][nx] == 1) continue;

			if (nexCost < Visited[ny][nx][nexK])
			{
				Visited[ny][nx][nexK] = nexCost;
				q.push({ nexCost, ny, nx, nexK });
			}
		}
		if (curK > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int ny = y + dy2[i];
				int nx = x + dx2[i];
				int nexCost = cost + 1;
				int nexK = curK - 1; 

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (Map[ny][nx] == 1) continue;

				if (nexCost < Visited[ny][nx][nexK])
				{
					Visited[ny][nx][nexK] = nexCost;
					q.push({ nexCost, ny, nx, nexK });
				}
			}
		}
	}

	if (output == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << output << endl;
	}

	return 0;
}