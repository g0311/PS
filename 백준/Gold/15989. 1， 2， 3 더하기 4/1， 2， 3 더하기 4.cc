#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int DP[10001][4];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(DP, 0, sizeof(DP));
		DP[1][1] = 1;
		DP[2][1] = 1;
		DP[2][2] = 1;
		DP[3][1] = 1;
		DP[3][2] = 1;
		DP[3][3] = 1;
		for (int i = 4; i <= n; i++)
		{
			DP[i][1] = DP[i - 1][1];
			DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
			DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
		}
		cout << DP[n][1] + DP[n][2] + DP[n][3] << endl;
	}

	return 0;
}
