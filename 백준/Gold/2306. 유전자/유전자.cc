#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int DP[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	for (int length = 2; length <= str.size(); length++)
	{
		for (int i = 0; i <= str.size() - length; i++)
		{
			int j = i + length - 1;

			DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);

			if ((str[i] == 'a' && str[j] == 't') || (str[i] == 'g' && str[j] == 'c'))
			{
				DP[i][j] = max(DP[i][j], DP[i + 1][j - 1] + 2);
			}

			for (int k = i; k < j; k++)
			{
				DP[i][j] = max(DP[i][j], DP[i][k] + DP[k + 1][j]);
			}
		}
	}

	cout << DP[0][str.size() - 1] << endl;

	return 0;
}

/*
a,t or g,c
a, c or g,t
*/