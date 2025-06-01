#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007
#define MOD 10'007

int DP[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;

	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 2]) % MOD;
	}
	cout << DP[n];

	return 0;
}