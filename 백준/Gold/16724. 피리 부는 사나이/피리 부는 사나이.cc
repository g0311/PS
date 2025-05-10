#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int n, m;
string Map[1000];
int Visited[1000][1000];
int output;

bool Solve(int x, int y)
{
	if (Visited[y][x] == 1)
		return true;
	if (Visited[y][x] == 2)
		return false;

	Visited[y][x] = 1;
	int nexX = 0, nexY = 0;
	switch (Map[y][x])
	{
	case 'L':
		nexX = x - 1; nexY = y;
		break;
	case 'R':
		nexX = x + 1; nexY = y;
		break;
	case 'D':
		nexX = x; nexY = y + 1;
		break;
	case 'U':
		nexX = x; nexY = y - 1;
		break;
	}
	if (nexX < 0 || nexX >= m || nexY < 0 || nexY >= n)
		return false;

	bool tf = Solve(nexX, nexY);
	Visited[y][x] = 2;
	return tf;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> Map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Solve(j, i))
				output++;
		}
	}

	cout << output;

	return 0;
}
