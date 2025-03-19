#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int map[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> y >> x;
		map[y][x] = 1;
	}

	queue<pair<int, int>> q;
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	int output = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int curOutput = 0;
			if(map[i][j] == 1)
			{
				q.push({ i,j });
				map[i][j] = 2;
				curOutput++;
			}
			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for (int t = 0; t < 4; t++)
				{
					int nex = x + dx[t];
					int ney = y + dy[t];
					if (nex <= 0 || nex > M || ney <= 0 || ney > N)
						continue;
					if (map[ney][nex] != 1)
						continue;

					q.push({ ney,nex });
					map[ney][nex] = 2;
					curOutput++;
				}
			}
			output = max(output, curOutput);
		}
	}
	cout << output;

	return 0;
}