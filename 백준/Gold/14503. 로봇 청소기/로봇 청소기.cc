#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int r, c, d;
	int map[50][50];
	int dx[] = { 0, 1, 0, -1 };//북동남서
	int dy[] = { -1, 0, 1, 0 };

	int output = 0;

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	while (true)
	{
		if (map[r][c] == 0)
		{
			map[r][c] = 2;
			output++;
		}

		int isAvail = false;
		for (int i = 0; i < 4; i++)
		{
			if (map[r + dy[i]][c + dx[i]] == 0)
				isAvail = true;
		}

		if (isAvail)
		{
			for (int i = 1; i <= 4; i++)
			{
				d = (d + 3) % 4;
				if (map[r + dy[d]][c + dx[d]] == 0)
				{
					r = r + dy[d];
					c = c + dx[d];
					break;
				}
			}
		}
		else
		{
			r = r - dy[d];
			c = c - dx[d];
			if (map[r][c] == 1)
				break;
		}
	}

	cout << output;


	return 0;
}

/*
4 60 4
2 50 2
4 40 3
3 30 1
1 20
4 40
6  5 6

*/