#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

ll perm(ll x, ll y)
{
	int result = 1;
	for (int i = 0; i < y; i++)
	{
		result = result * (x - i) % INF;
	}
	return result;
}

ll fact(ll x)
{
	ll result = 1;
	for (int i = 1; i <= x; i++)
	{
		result = result * i % INF;
	}
	return result;
}

ll power(ll X, ll Y)
{
	ll result = 1;
	while (Y >= 1)
	{
		if (Y % 2 == 1)
		{
			result = result * X % INF;
		}
		X = X * X % INF;
		Y /= 2;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	int sum = 0;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int X = K - sum;
	
	cout << perm(N + X, N);

	//N+1 H X
	//N+X C N * N!
	//(N+X)! / X!
	//N+X P N %MOD 아.

	return 0;
}
/*
123456 5
512346
*/