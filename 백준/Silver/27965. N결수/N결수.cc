#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	ll cur = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp > 0)
		{
			cur *= 10;
			temp /= 10;
		}
		cur += i;
		cur %= k;
	}
	cout << cur;

	return 0;
}
