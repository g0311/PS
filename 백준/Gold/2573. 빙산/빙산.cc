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

int Map[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> Map[i][j];
		}
	}

	int Temp[301][301];
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };
	int output = 0;
	while(true)
	{
		memset(Temp, 0, sizeof(Temp));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if(Map[i][j] == 0)
					continue;

				int ct = 0;
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M) 
						continue;
					if (Map[ny][nx] == 0)
					{
						ct++;
					}
				}
				Temp[i][j] = max(0, Map[i][j] - ct);
			}
		}
		memcpy(Map, Temp, sizeof(Map));
		memset(Temp, 0, sizeof(Temp));

		output++;

		int ct = 0;
		bool allMelted = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] == 0 || Temp[i][j])
					continue;
				allMelted = false;

				queue<pair<int, int>> q;
				q.push({ i, j });
				Temp[i][j] = 1;
				ct++;
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					if (Map[y][x] == 0)
						continue;
					for (int k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M)
							continue;
						if (Temp[ny][nx])
							continue;
						if (Map[ny][nx] == 0)
							continue;

						Temp[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}
		}
		if (ct >= 2) 
		{
			cout << output << endl;
			break;
		}
		if (allMelted) 
		{
			cout << 0 << endl;
			break;
		}
	}

	return 0;
}