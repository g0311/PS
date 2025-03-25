#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

int N, R, G, B;

int Case[11][4];

ll CountCase(int a, int c)
{
	ll out1 = 1;
	int b = a / c;
	for (int i = a; i > b; i--)
	{
		out1 *= i;
	}

	ll out2 = 1;
	for (int i = 1; i <= b; i++)
	{
		out2 *= i;
	}

	for (int i = 1; i < c; i++)
	{
		out1 /= out2;
	}
	return out1;
}

ll Solve(int lv, int R, int G, int B)
{
	if (R < 0 || G < 0 || B < 0)
		return 0;
	if (lv == N + 1)
		return 1;

	ll output = 0;

	output += Solve(lv + 1, R - lv, G, B);
	output += Solve(lv + 1, R, G - lv, B);
	output += Solve(lv + 1, R, G, B - lv);

	if(lv % 2 == 0)
	{
		output += Solve(lv + 1, R - lv / 2, G - lv / 2, B) * Case[lv][2];
		output += Solve(lv + 1, R - lv / 2, G, B - lv / 2) * Case[lv][2];
		output += Solve(lv + 1, R, G - lv / 2, B - lv / 2) * Case[lv][2];
	}

	if (lv % 3 == 0)
	{
		output += Solve(lv + 1, R - lv / 3, G - lv / 3, B - lv / 3) * Case[lv][3];
	}

	return output;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> G >> B;

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			Case[i][j] = CountCase(i, j);
		}
	}

	cout << Solve(1, R, G, B);

	return 0;
}