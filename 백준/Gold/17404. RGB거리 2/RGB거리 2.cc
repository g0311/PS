#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

int EXP[1001][3];
int DP[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> EXP[i][0];
		cin >> EXP[i][1];
		cin >> EXP[i][2];
	}
	int ans = INF;

	DP[1][0] = EXP[1][0];
	DP[1][1] = DP[1][2] = INF;
	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + EXP[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + EXP[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + EXP[i][2];
	}
	ans = min(ans, min(DP[N][1], DP[N][2]));
	memset(DP, 0, sizeof(DP));

	DP[1][1] = EXP[1][1];
	DP[1][0] = DP[1][2] = INF;
	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + EXP[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + EXP[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + EXP[i][2];
	}
	ans = min(ans, min(DP[N][0], DP[N][2]));
	memset(DP, 0, sizeof(DP));

	DP[1][2] = EXP[1][2];
	DP[1][0] = DP[1][1] = INF;
	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + EXP[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + EXP[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + EXP[i][2];
	}
	ans = min(ans, min(DP[N][0], DP[N][1]));
	memset(DP, 0, sizeof(DP));

	cout << ans;
	return 0;
}