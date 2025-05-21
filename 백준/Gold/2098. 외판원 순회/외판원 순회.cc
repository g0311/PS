#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int N;
int map[16][16];
int DP[16][1 << 16];

int DFS(int Cur, int Visit)
{
	if (Visit == (1 << N) - 1)
	{
		if (map[Cur][0] == 0)
			return INF;
		else
			return map[Cur][0];
	}

	if(DP[Cur][Visit] != -1)
		return DP[Cur][Visit];

	DP[Cur][Visit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (map[Cur][i] == 0)
			continue;
		if ((Visit & (1 << i)) == (1 << i))
		{
			continue;
		}
		DP[Cur][Visit] = min(DP[Cur][Visit], DFS(i, Visit | (1 << i)) + map[Cur][i]);
	}
	return DP[Cur][Visit];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	memset(DP, -1, sizeof(DP));
	cout << DFS(0, 1);

	return 0;
}
