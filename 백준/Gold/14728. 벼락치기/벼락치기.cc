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

int DP[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, T;
	cin >> N >> T;

	vector<pair<int, int>> p(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j < p[i].first)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - p[i].first] + p[i].second);
			}
		}
	}
	cout << DP[N][T] << endl;

	return 0;
}