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

ll DP[65][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	DP[1][0] = 1;
	for (int i = 1; i < 10; i++)
	{
		DP[1][i] = 1 + DP[1][i - 1];
	}
	for (int i = 2; i < 65; i++)
	{
		DP[i][0] = DP[i - 1][9];
		for (int j = 1; j < 10; j++)
		{
			DP[i][j] = DP[i - 1][9] - DP[i - 1][j - 1];
			DP[i][j] += DP[i][j - 1];
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		
		cout << DP[n][9] << endl;
	}

	return 0;
}
