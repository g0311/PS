#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

ll DP[31][31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 30; i++)
		DP[i][0] = 1;

	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= 30; j++)
		{
			if (i < j)
				continue;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
			return 0;
		
		cout << DP[N][N] << endl;
	}

	return 0;
}
