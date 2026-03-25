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

int DP[1001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, C0, D0;
	cin >> N >> M >> C0 >> D0;
	
	for (int j = C0; j <= N; ++j) 
	{
		DP[j] = max(DP[j], DP[j - C0] + D0);
	}

	for (int i = 1; i <= M; ++i)
	{
		int a, b, c, d;
		//남은 속, 필요 속, 피, 가격
		cin >> a >> b >> c >> d;
		int MaxDump = a / b;

		for (int k = 0; k < MaxDump; ++k)
		{
			for (int j = N; j >= c; --j)
			{
				DP[j] = max(DP[j], DP[j - c] + d);
			}
		}
	}

	cout << DP[N] << endl;

	return 0;
}
