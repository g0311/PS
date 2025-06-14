#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int M, N;

int Map[500][500];
int DP[500][500];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int DFS(int x, int y)
{
	if (DP[y][x] != -1)
		return DP[y][x];

	if (x == N - 1 && y == M - 1)
		return 1;

	int ct = 0;
	for (int i = 0; i < 4; i++)
	{
		int nex = x + dx[i];
		int ney = y + dy[i];
		if (nex < 0 || nex >= N || ney < 0 || ney >= M)
			continue;

		if (Map[y][x] > Map[ney][nex])
		{
			ct += DFS(nex, ney);
		}
	}
	return DP[y][x] = ct;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}
	memset(DP, -1, sizeof(DP));

	cout << DFS(0, 0);

	return 0;
}
