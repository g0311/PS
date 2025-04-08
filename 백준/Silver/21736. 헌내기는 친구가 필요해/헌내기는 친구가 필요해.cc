#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

char Map[600][600];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'I')
			{
				y = i; x = j;
			}
		}
	}

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	
	queue<pair<int, int>> q;
	q.push({ y,x });
	Map[y][x] = '.';
	int output = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (Map[ny][nx] != '.' && Map[ny][nx] != 'X')
			{
				q.push({ ny,nx });

				if (Map[ny][nx] == 'P')
					output++;

				Map[ny][nx] = '.';
			}
		}
	}
	if (output != 0)
		cout << output;
	else
		cout << "TT";

	return 0;
}