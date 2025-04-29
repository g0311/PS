
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000

int DP[1001][2][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	DP[1][0][0] = 1; // 1일차 지각 0회 결석 0회
	DP[1][0][1] = 1; // 1일차 지각 0회 결석 1회
	DP[1][0][2] = 0; // 1일차 지각 0회 결석 2회
	DP[1][1][0] = 1; // 1일차 지각 1회 결석 0회
	DP[1][1][1] = 0; // 1일차 지각 1회 결석 1회
	DP[1][1][2] = 0; // 1일차 지각 1회 결석 2회
	for (int i = 2; i <= N; i++)
	{
		DP[i][0][0] = (DP[i - 1][0][0] + DP[i - 1][0][1] + DP[i - 1][0][2]) % INF;
		DP[i][0][1] = DP[i - 1][0][0];
		DP[i][0][2] = DP[i - 1][0][1];
		DP[i][1][0] = (DP[i - 1][1][0] + DP[i - 1][1][1] + DP[i - 1][1][2] + DP[i - 1][0][0] + DP[i - 1][0][1] + DP[i - 1][0][2]) % INF;
		DP[i][1][1] = DP[i - 1][1][0];
		DP[i][1][2] = DP[i - 1][1][1];
	}
	int output = 0;
	for (int i = 0; i < 3; i++)
	{
		output += DP[N][0][i];
		output %= INF;
	}
	for (int i = 0; i < 3; i++)
	{
		output += DP[N][1][i];
		output %= INF;
	}
	cout << output << endl;

	return 0;
}

/*
0번 지각 0번 연속 결석
0번 지각 1번 "
0번 지각 2번 "
1번 지각 0번 "
1번 지각 1번 "
1번 지각 2번 "
*/