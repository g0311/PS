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

int Map[100][70];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	int ct = 0;
	int Visited[100][70] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Visited[i][j]) continue;
			int curHeight = Map[i][j];
			bool bIsPeak = true;

			queue<pair<int, int>> q;
			q.push({ i, j });
			Visited[i][j] = 1;
			while(!q.empty())
			{
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 8; dir++)
				{
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
					if(Map[ny][nx] > curHeight)
					{
						bIsPeak = false;
					}
					
					if (Map[ny][nx] == curHeight && Visited[ny][nx] == 0)
					{
						Visited[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}

			if (bIsPeak) ct++;
		}
	}

	cout << ct << endl;
	return 0;
}