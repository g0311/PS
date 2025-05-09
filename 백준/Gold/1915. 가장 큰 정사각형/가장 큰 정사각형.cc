#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int map[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j + 1] = str[j] - '0';
		}
	}

	int output = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
				continue;

			int _1 = map[i - 1][j - 1];
			int _2 = map[i][j - 1];
			int _3 = map[i - 1][j];
			int minNo = min(_1, min(_2, _3));

			if (_1 != 0 && _2 != 0 && _3 != 0)
			{
				map[i][j] = minNo + 1;
			}
			output = max(output, map[i][j]);
		}
	}
	cout << output * output;

	return 0;
}
