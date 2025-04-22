#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

string Map[10];
vector<pair<int, int>> blanks;

void Solve(int idx)
{
	if (idx == blanks.size())
	{
		for (int i = 0; i < 9; i++)
		{
			cout << Map[i] << endl;
		}
		exit(0);
	}
	int y = blanks[idx].first;
	int x = blanks[idx].second;
	bool used[10] = { false };
	for (int i = 0; i < 9; i++)
	{
		used[Map[y][i] - '0'] = true;
		used[Map[i][x] - '0'] = true;
	}
	int ny, nx;
	ny = y - (y % 3);
	nx = x - (x % 3);
	for (int k = ny; k <= ny + 2; k++)
	{
		for (int r = nx; r <= nx + 2; r++)
		{
			used[Map[k][r] - '0'] = true;
		}
	}
	for (char c = '1'; c <= '9'; c++)
	{
		if (!used[c - '0'])
		{
			Map[y][x] = c;
			Solve(idx + 1);
			Map[y][x] = '0';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		cin >> Map[i];
		for(int j = 0; j < 9; j++)
		{
			if (Map[i][j] == '0')
				blanks.push_back({ i,j });
		}
	}
	Solve(0);

	return 0;
}

/*
행
열
블럭
1 1
2 1
3 1
4 4
5 4
6 4
7 7
8 7
9 7
*/