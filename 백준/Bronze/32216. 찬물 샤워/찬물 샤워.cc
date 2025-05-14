#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k, T;
	cin >> n >> k >> T;
	vector<int>arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int output = 0;
	for (int i = 0; i < n; i++)
	{
		if (T > k)
		{
			T = T + arr[i + 1] - abs(T - k);
		}
		else if (T < k)
		{
			T = T + arr[i + 1] + abs(T - k);
		}
		else
		{
			T = T + arr[i + 1];
		}
		output += abs(T - k);
	}
	cout << output;

	return 0;
}
