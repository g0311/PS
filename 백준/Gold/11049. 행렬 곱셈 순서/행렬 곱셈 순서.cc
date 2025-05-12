#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2.147e9

int DP[501][501];
vector<pair<int, int>> rc;

int Solve(int st, int ed)
{
	if (DP[st][ed] != -1)
		return DP[st][ed];
	if (st == ed)
		return DP[st][ed] = 0;

	DP[st][ed] = INF;

	for (int i = st; i < ed; i++)
	{
		int cur = Solve(st, i) + Solve(i + 1, ed);
		cur += rc[st].first * rc[i].second * rc[ed].second;

		DP[st][ed] = min(DP[st][ed], cur);
	}

	return DP[st][ed];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	rc.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> rc[i].first >> rc[i].second;
	}

	memset(DP, -1, sizeof(DP));
	Solve(1, N);
	cout << DP[1][N];

	return 0;
}
