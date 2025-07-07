#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int DP[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;
	while (TC--)
	{
		memset(DP, 0, sizeof(DP));
		int K;
		cin >> K;
		vector<int> book(K + 1);
		vector<int> prefixSum(K + 1, 0);
		for (int i = 1; i <= K; i++)
		{
			cin >> book[i];
			prefixSum[i] = prefixSum[i - 1] + book[i];
		}
		
		for (int len = 2; len <= K; len++)
		{
			for (int i = 1; i + len - 1 <= K; i++)
			{
				int j = i + len - 1;
				DP[i][j] = INF;
				for (int k = i; k <= j; k++)
				{
					int cost = prefixSum[j] - prefixSum[i - 1];
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + cost);
				}
			}
		}
		cout << DP[1][K] << endl;
	}

	return 0;
}