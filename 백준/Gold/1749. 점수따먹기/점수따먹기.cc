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

int Map[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			Map[i][j] += Map[i - 1][j] + Map[i][j - 1] - Map[i - 1][j - 1];
		}
	}

	int Ans = -INF;
	for (int r1 = 1; r1 <= N; r1++)
	{
		for (int r2 = r1; r2 <= N; r2++)
		{
			for (int c1 = 1; c1 <= M; c1++)
			{
				for (int c2 = c1; c2 <= M; c2++)
				{
					int Sum = Map[r2][c2] - Map[r1 - 1][c2] - Map[r2][c1 - 1] + Map[r1 - 1][c1 - 1];
					Ans = max(Ans, Sum);
				}
			}
		}
	}
	cout << Ans;

	return 0;
}