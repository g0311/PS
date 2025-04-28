
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
#define INF 1'000'000'007

ll Factorial(int n)
{
	ll result = 1;
	for (int i = 2; i <= n; i++)
	{
		result *= i;
		result %= INF;
	}
	return result;
}

ll Power(ll base, ll exp)
{
	ll result = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result *= base;
			result %= INF;
		}
		base *= base;
		base %= INF;
		exp /= 2;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	// N! % INF * (M! * (N-M)!)^-1 % INF
	// N! % INF * (M!% INF * (N-M)!% INF)^INF-2 % INF
	ll top = Factorial(N);
	ll bottom = (Factorial(M) * Factorial(N - M)) % INF;
	ll bottom_inv = Power(bottom, INF - 2) % INF;
	ll result = (top * bottom_inv) % INF;
	cout << result;

	return 0;
}