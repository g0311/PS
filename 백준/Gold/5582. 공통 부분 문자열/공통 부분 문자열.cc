#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int DP[4001][4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;

	int max_len = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j]) 
			{
				if (i == 0 || j == 0)
				{
					DP[i][j] = 1;
				}
				else
				{
					DP[i][j] = DP[i - 1][j - 1] + 1;
				}
			}
			else 
			{
				DP[i][j] = 0;
			}
			max_len = max(max_len, DP[i][j]);
		}
	}
	cout << max_len << endl;

	return 0;
}