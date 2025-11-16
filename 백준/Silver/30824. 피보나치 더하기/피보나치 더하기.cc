#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

ll DP[86];
ll k, x;

bool Per(int R, ll curCt)
{
	if (R == 0)
	{
		if (curCt == x)
			return true;
		return false;
	}

	for (int i = 1; i <= 85; ++i)
	{
		if (Per(R - 1, curCt + DP[i]))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	DP[1] = DP[2] = 1;
	for (int i = 3; i <= 85; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	// 피보나치 전부 계산

	int TC;
	cin >> TC;

	while (TC--)
	{
		cin >> k >> x;
		cout << (Per(k, 0) ? "YES" : "NO") << endl;
		// 계산 및 조건 체크
	}

	return 0;
}