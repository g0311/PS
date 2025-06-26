#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

ll DP[117];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 3];
	}
	cout << DP[n];

	return 0;
}