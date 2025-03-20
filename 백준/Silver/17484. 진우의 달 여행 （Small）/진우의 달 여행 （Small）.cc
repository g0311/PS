#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'

int n, m;
int map[7][7];
int output = 100'000'000;
void Solve(int x, int y, int curP, int bef)
{
	curP += map[y][x];
	if (curP > output)
		return;

	if (y == n)
	{
		output = curP;
		return;
	}

	for (int i = -1; i < 2; i++)
	{
		if (bef == i)
			continue;
		int nex = x + i;
		if (nex <= 0 || nex > m)
			continue;

		Solve(nex, y + 1, curP, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		Solve(i, 1, 0, 2);
	}

	cout << output;

	return 0;
}