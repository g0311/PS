#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int DP[101][101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1 = " ", str2 = " ", str3 = " ";
	string temp;
	cin >> temp;
	str1 += temp;
	cin >> temp;
	str2 += temp;
	cin >> temp;
	str3 += temp;

	for (int i = 1; i < str1.size(); i++)
	{
		for (int j = 1; j < str2.size(); j++)
		{
			for (int k = 1; k < str3.size(); k++)
			{
				if (str1[i] == str2[j] && str2[j] == str3[k])
				{
					DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					DP[i][j][k] = max({ DP[i - 1][j][k], DP[i][j - 1][k], DP[i][j][k - 1] });
				}
			}
		}
	}
	cout << DP[str1.size() - 1][str2.size() - 1][str3.size() - 1] << endl;

	return 0;
}