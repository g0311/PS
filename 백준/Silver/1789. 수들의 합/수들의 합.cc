#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll S;
	cin >> S;

	int ct = 0;
	ll sum = 0;
	while (sum <= S)
	{
		ct++;
		sum += ct;
	}
	cout << ct - 1 << endl;

	return 0;
}
