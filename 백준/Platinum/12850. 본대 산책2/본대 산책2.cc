#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

ll DP[8][8] =
{
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

void multi(ll(*x)[8], ll(*y)[8], ll(*out)[8])
{
	ll temp[8][8];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				temp[i][j] = (temp[i][j] + (x[i][k] % INF) * (y[k][j] % INF)) % INF;
			}
		}
	}
	memcpy(out, temp, sizeof(temp));
	return;
}

int solve(int top)
{
	ll result[8][8];
	memset(result, 0, sizeof(result));
	for (int i = 0; i < 8; i++)
		result[i][i] = 1;

	while (top > 0)
	{
		if (top % 2 == 1)
		{
			multi(result, DP, result);
		}
		multi(DP, DP, DP);
		top /= 2;
	}

	return result[0][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int D;
	cin >> D;

	cout << solve(D);

	return 0;
}
