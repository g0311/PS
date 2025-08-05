#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

int N, C;
vector<ll> arr;

bool canInstall(ll minDist) 
{
	int count = 1;
	ll last = arr[0];

	for (int i = 1; i < N; i++) 
	{
		if (arr[i] - last >= minDist) 
		{
			count++;
			last = arr[i];
		}
	}
	return count >= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> C;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	ll low = 1;
	ll high = arr[N - 1] - arr[0];
	ll answer = 0;

	while (low <= high) 
	{
		ll mid = (low + high) / 2;
		if (canInstall(mid)) 
		{
			answer = mid;
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}

	cout << answer;

	return 0;
}