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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	
	vector<int> Arr(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
	}

	vector<int> LDP(N + 1, 1);
	vector<int> RDP(N + 1, 1);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (Arr[i] > Arr[j])
			{
				LDP[i] = max(LDP[i], LDP[j] + 1);
			}
		}
	}

	for (int i = N; i >= 1; --i)
	{
		for (int j = N; j > i; --j)
		{
			if (Arr[i] < Arr[j])
			{
				RDP[i] = max(RDP[i], RDP[j] + 1);
			}
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int Query;
		cin >> Query;

		cout << LDP[Query] + RDP[Query] - 1 << endl;
	}

	return 0;
}