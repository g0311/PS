#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

/*
sigma(1<=a<b<=n) xa*xb

x1 * (x2 + x3 + ... + xn) +
x2 * (x3 + x4 + ... + xn) +
...
xn-1 * (xn)

xn = arr[n] - arr[n-1]
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> arr(n + 1);
	cin >> arr[1];
	for (int i = 2; i <= n; ++i)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	ll out = 0;
	for (int i = 1; i < n; ++i)
	{
		out += ((arr[i] - arr[i - 1]) * (arr[n] - arr[i]));
	}

	cout << out;

	return 0;
}