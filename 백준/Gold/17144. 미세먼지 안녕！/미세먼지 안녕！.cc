#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[50][50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int R, C, T;
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
		}
	}

	int up = -1, down = -1;
	for (int i = 0; i < R; i++)
	{
		if (Map[i][0] == -1)
		{
			up = i;
			break;
		}
	}
	down = up + 1;

	for (int t = 0; t < T; t++)
	{
		int temp[50][50] = { 0 };
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (Map[i][j] == -1) continue;
				int dust = Map[i][j] / 5;
				int cnt = 0;
				for (int di = -1; di <= 1; di++)
				{
					for (int dj = -1; dj <= 1; dj++)
					{
						if (abs(di) + abs(dj) != 1) continue;
						int ni = i + di, nj = j + dj;
						if (ni < 0 || ni >= R || nj < 0 || nj >= C || Map[ni][nj] == -1) continue;
						temp[ni][nj] += dust;
						cnt++;
					}
				}
				temp[i][j] += Map[i][j] - dust * cnt;
			}
		}
		
		// Upward air purifier
		for (int i = up - 1; i > 0; i--)
		{
			temp[i][0] = temp[i - 1][0];
		}
		for (int j = 0; j < C - 1; j++)
		{
			temp[0][j] = temp[0][j + 1];
		}
		for (int i = 0; i < up; i++)
		{
			temp[i][C - 1] = temp[i + 1][C - 1];
		}
		for (int j = C - 1; j > 0; j--)
		{
			temp[up][j] = temp[up][j - 1];
		}
		temp[up][1] = 0; // Reset the air purifier position

		// Downward air purifier
		for (int i = down + 1; i < R - 1; i++)
		{
			temp[i][0] = temp[i + 1][0];
		}
		for (int j = 0; j < C - 1; j++)
		{
			temp[R - 1][j] = temp[R - 1][j + 1];
		}
		for (int i = R - 1; i > down; i--)
		{
			temp[i][C - 1] = temp[i - 1][C - 1];
		}
		for (int j = C - 1; j > 0; j--)
		{
			temp[down][j] = temp[down][j - 1];
		}
		temp[down][1] = 0; // Reset the air purifier position

		temp[up][0] = -1;
		temp[down][0] = -1;

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				Map[i][j] = temp[i][j];
			}
		}
	}
	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[i][j] != -1)
			{
				result += Map[i][j];
			}
		}
	}

	cout << result << endl;

	return 0;
}