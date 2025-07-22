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

int Map[51][51];
int Visited[51][51];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int wallBits[] = { 1, 2, 4, 8 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}

	queue<pair<int, int>> q;
	vector<int> RoomSizes(1, 0);
	int roomCt = 0;
	int maxSize = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!Visited[i][j])
			{
				roomCt++;

				q.push({ i, j });
				Visited[i][j] = roomCt;
				int size = 1;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int dir = 0; dir < 4; dir++) 
					{
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx >= 0 && nx < M && ny >= 0 && ny < N) 
						{
							if (Visited[nx][ny] || (Map[x][y] & wallBits[dir])) 
							{
								continue;
							}
							q.push({ nx, ny });
							Visited[nx][ny] = roomCt;
							size++;
						}
					}
				}
				maxSize = max(maxSize, size);
				RoomSizes.push_back(size);
			}
		}
	}

	int max2Size = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N)
				{
					if (Map[i][j] & wallBits[dir])
					{
						int room1 = Visited[i][j];
						int room2 = Visited[nx][ny];
						if (room1 != room2)
						{
							max2Size = max(max2Size, RoomSizes[room1] + RoomSizes[room2]);
						}
					}
				}
			}
		}
	}
	cout << roomCt << endl << maxSize << endl << max2Size;

	return 0;
}