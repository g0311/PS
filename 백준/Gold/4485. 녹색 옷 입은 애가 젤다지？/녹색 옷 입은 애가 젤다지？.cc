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

int Map[126][126];
int DP[126][126];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	int ct = 0;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		ct++;
		memset(Map, 0, sizeof(Map));
		memset(DP, -1, sizeof(DP));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> Map[i][j];
			}
		}
		
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -Map[1][1], {1, 1} });
		DP[1][1] = Map[1][1];


		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (DP[x][y] < cost) continue;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
				{
					if (DP[nx][ny] == -1 || DP[nx][ny] > cost + Map[nx][ny])
					{
						DP[nx][ny] = cost + Map[nx][ny];
						pq.push({ -DP[nx][ny], {nx, ny} });
					}
				}
			}
		}

		cout << "Problem " << ct << ": " << DP[N][N] << endl;
	}

	return 0;
}