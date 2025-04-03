#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int N, M;

string Map[50];
int DP[50][50];
int Visited[50][50];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int DFS(int y, int x)
{
	if (Visited[y][x] == 1)
	{
		cout << -1 << endl;
		exit(0);
	}

	if (DP[y][x] != -1)
		return DP[y][x];

	Visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ney = y + dy[i] * (Map[y][x] - '0');
		int nex = x + dx[i] * (Map[y][x] - '0');
		if (ney < 0 || ney >= N || nex < 0 || nex >= M || Map[ney][nex] == 'H')
		{
			DP[y][x] = max(DP[y][x], 1);
			continue;
		}
		DP[y][x] = max(DP[y][x], DFS(ney, nex) + 1);
	}
	Visited[y][x] = 0;
	return DP[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}

	cout << DFS(0, 0);

	return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10
    1       1 1 
*/