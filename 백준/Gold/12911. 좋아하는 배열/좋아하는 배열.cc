#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807
#define MOD 1'000'000'007

int N, K;
ll DP[11][100001];
//DP[i][j] = i번째 수가 j일때 경우의 수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= K; ++i) 
	{
		DP[1][i] = 1;
	}

	for (int id = 2; id <= N; ++id)
	{
		ll total = 0;
		for (int i = 1; i <= K; ++i)
		{
			total = (total + DP[id - 1][i]) % MOD;
		}

		for (int i = 1; i <= K; ++i)
		{
			ll invalid = 0;
			for (int j = i * 2; j <= K; j += i)
			{
				invalid = (invalid + DP[id - 1][j]) % MOD;
			}
			DP[id][i] = (total - invalid + MOD) % MOD;
		}
	}

	ll out = 0;
	for (int i = 0; i <= K; ++i)
	{
		out = (out + DP[N][i]) % MOD;
	}

	cout << out;

	return 0;
}
