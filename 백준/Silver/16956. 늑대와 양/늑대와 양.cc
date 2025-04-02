#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long

char Map[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	cin >> R >> C;

	bool isAvail = true;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int ney = i + dy[k];
					int nex = j + dx[k];
					if (ney < 0 || ney >= R || nex < 0 || nex >= C)
						continue;

					if (Map[ney][nex] == '.')
					{
						Map[ney][nex] = 'D';
					}
				}
			}
			if (Map[i][j] == 'W')
			{
				for (int k = 0; k < 4; k++)
				{
					int ney = i + dy[k];
					int nex = j + dx[k];
					if (ney < 0 || ney >= R || nex < 0 || nex >= C)
						continue;

					if (Map[ney][nex] == 'S')
					{
						isAvail = false;
					}
				}
			}
		}
	}

	if (!isAvail)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << 1 << endl;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << Map[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}