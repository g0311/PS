
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000

int DP[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int>arr(n + 1);
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		DP[i][i] = 1;
	}
	int m;
	cin >> m;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (arr[i] == arr[j])
			{
				if (j - i == 1)
				{
					DP[i][j] = 1;
				}
				else
				{
					if (DP[i + 1][j - 1] == 1)
					{
						DP[i][j] = 1;
					}
					else
					{
						DP[i][j] = 0;
					}
				}
			}
			else
			{
				DP[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i ++)
	{
		int st, ed;
		cin >> st >> ed;
		cout << DP[st][ed] << endl;
	}

	return 0;
}

/*
1 o
1 5 x
1 5 1 o
1 5 1 1 x
1 5 1 1 5 x
1 5 1 1 5 1 o
1 ~ 6 이 펠린드롬?
1 == 6 이고, 2 ~ 4 가 펠린드롬

*/