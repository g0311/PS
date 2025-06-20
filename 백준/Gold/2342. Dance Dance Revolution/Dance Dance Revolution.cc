#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int DP[100001][5][5];

int Point(int bef, int cur)
{
	if (bef == cur) return 1;
	if (bef == 0) return 2;
	if (abs(bef - cur) == 2) return 4;

	return 3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;
	arr.push_back(-1);
	while (true)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		arr.push_back(x);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				DP[i][j][k] = INF;
			}
		}
	}
	DP[0][0][0] = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (DP[i - 1][j][k] == INF) continue;

				if(arr[i] != k)
					DP[i][arr[i]][k] = min(DP[i][arr[i]][k], DP[i - 1][j][k] + Point(j, arr[i]));
	
				if (arr[i] != j)
					DP[i][j][arr[i]] = min(DP[i][j][arr[i]], DP[i - 1][j][k] + Point(k, arr[i]));
			}
		}
	}

	int minP = INF;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (DP[arr.size() - 1][i][j] != INF)
			{
				minP = min(minP, DP[arr.size() - 1][i][j]);
			}
		}
	}
	cout << minP;

	return 0;
}