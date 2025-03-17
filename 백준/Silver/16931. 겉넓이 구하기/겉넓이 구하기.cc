#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
#define endl '\n'

int map[100][100][100];
int visit[100][100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < M; j++)
		{
            int a;
            cin >> a;
            for (int k = 0; k < a; k++)
            {
                map[i][j][k] = 1;
            }
        }
    }
    queue<tuple<int, int, int>> q;
	q.push(make_tuple(0,0,0));
	visit[0][0][0] = 1;

    int dx[6] = { -1, 0, 0, 1, 0, 0 };
    int dy[6] = { 0, -1, 0, 0, 1, 0 };
    int dz[6] = { 0, 0, -1, 0, 0, 1 };
    int output = 0;
    while (!q.empty())
    {
        int x, y, z;
		tie(x, y, z) = q.front();
        q.pop();

        int curSize = 6;
        for (int i = 0; i < 6; i++)
        {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= 100)
				continue;

			if (map[nx][ny][nz] == 1)
			{
                if(visit[nx][ny][nz] == 0)
                {
                    q.push(make_tuple(nx, ny, nz));
                    visit[nx][ny][nz] = visit[x][y][z] + 1;
                }
                curSize--;
            }
        }
        output += curSize;
    }
    cout << output;

    return 0;
}

/*
6
11
16

*/