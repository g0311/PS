#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[20][20];
int Check[20][20];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}

	
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == k) continue;
			for (int j = 0; j < N; j++)
			{
				if (j == k || j == i) continue;

				if (Map[i][k] + Map[k][j] < Map[i][j])
				{
					cout << -1;
					return 0;
				}

				if (Map[i][j] == Map[i][k] + Map[k][j])
				{
					Check[i][j] = 1;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Check[i][j] != 1)
			{
				ans += Map[i][j];
			}
		}
	}

	cout << ans / 2;
	return 0;
}

