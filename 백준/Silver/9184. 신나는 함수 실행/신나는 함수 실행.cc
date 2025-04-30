
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

int DP[101][101][101] = { 0 };

int Solve(int a, int b, int c)
{
	if (DP[a][b][c] != 0)
		return DP[a][b][c];

	if (a <= 50 or b <= 50 or c <= 50)
		return DP[a][b][c] = 1;

	if (a > 70 or b > 70 or c > 70)
		return DP[a][b][c] = Solve(70, 70, 70);

	if (a < b and b < c)
		return DP[a][b][c] = Solve(a, b, c - 1) + Solve(a, b - 1, c - 1) - Solve(a, b - 1, c);

	return DP[a][b][c] = Solve(a - 1, b, c) + Solve(a - 1, b - 1, c) + Solve(a - 1, b, c - 1) - Solve(a - 1, b - 1, c - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << Solve(a + 50, b + 50, c + 50) << endl;
	}

	return 0;
}
