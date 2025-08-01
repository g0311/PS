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
#define pll pair<ll,ll>
#define INF 1e9

int N, M;
int Map[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	bool t = true;
	int ct = 0;
	while (t)
	{
		ct++;
		t = false;

		queue<pair<int,int>> q;
		q.push({ 0, 0 });
		bool visited[101][101] = {};
		visited[0][0] = true;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			Map[y][x] = -1;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (!visited[ny][nx]) 
				{
					if (Map[ny][nx] == 1) continue;

					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] == 1)
				{
					int ct = 0;
					for (int d = 0; d < 4; d++)
					{
						int ny = i + dy[d];
						int nx = j + dx[d];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
						if (Map[ny][nx] == -1)
						{
							ct++;
						}
					}
					if (ct >= 2)
					{
						Map[i][j] = 2;
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] == 2)
				{
					Map[i][j] = -1;
				}
				if (Map[i][j] == 1)
				{
					t = true;
				}
			}
		}
	}

	cout << ct << endl;

	return 0;
}