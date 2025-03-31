#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1'000'000'000

//길이 i, 이전문자j, 나온문자들 k?
ll DP[101][10][1024];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		DP[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 1023; k++)
			{
				if(j > 0)
				{
					DP[i][j][k | (1 << j)] += DP[i - 1][j - 1][k];
				}
				if (j < 9)
				{
					DP[i][j][k | (1 << j)] += DP[i - 1][j + 1][k];
				}
				DP[i][j][k | (1 << j)] %= MOD;
			}
		}
	}

	
	ll output = 0;
	for (int i = 1; i <= 9; i++)
	{
		output += DP[n][i][1023];
		output %= MOD;
	}

	cout << output;

	return 0;
}
