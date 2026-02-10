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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int N, K;
char Arr[100001];
int DP[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	vector<int> IsStair(N + 1, 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
	}

	DP[1] = 1; DP[2] = 1; DP[3] = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (Arr[i] == Arr[i - 1] + 1 || Arr[i] == Arr[i - 1] - 1)
		{
			IsStair[i] = IsStair[i - 1] + 1;
		}

		DP[i] = DP[i - 1] + 1;
		if (i >= 2)
		{
			DP[i] = min(DP[i], DP[i - 2] + 1);
		}
		if (i >= 3)
		{
			DP[i] = min(DP[i], DP[i - 3] + 1);
		}
		if (i >= K)
		{
			if (IsStair[i] >= K)
			{
				DP[i] = min(DP[i], DP[i - K] + 1);
			}
		}
	}
	cout << DP[N];

	return 0;
}