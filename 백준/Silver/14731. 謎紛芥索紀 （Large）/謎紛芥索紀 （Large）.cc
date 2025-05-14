#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007


ll Pow(ll x, ll y)
{
	ll result = 1;
	while (y > 0)
	{
		if (y % 2 != 0)
		{
			result = (result * x) % INF;
		}
		x = (x * x) % INF;
		y /= 2;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int,int>> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	
	ll output = 0;
	for (int i = 0; i < N; i++)
	{
		ll c = arr[i].first;
		ll k = arr[i].second;
		
		if (k == 0)
			continue;

		c = (c * k) % INF; k--;
		output = (output + (Pow(2, k) * c) % INF) % INF;
	}
	cout << output << endl;

	return 0;
}
