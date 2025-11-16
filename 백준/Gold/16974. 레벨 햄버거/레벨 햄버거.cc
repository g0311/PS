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

pll BURGER[51] = {};
//bun, patty

ll CountPatty(ll lv, ll ct)
{
	if (ct == 0)
		return 0;
	if (lv == 0)
		return 1;

	ll bPp = BURGER[lv].first + BURGER[lv].second;
	ll out = 0;
	if (bPp == ct)
	{
		return BURGER[lv].second;
	}
	else if (bPp / 2 + 1 < ct)
	{
		ct -= BURGER[lv - 1].first + BURGER[lv-1].second + 2;
		return CountPatty(lv - 1, ct) + BURGER[lv - 1].second + 1;
	}
	else if (bPp / 2 + 1 == ct)
	{
		return BURGER[lv - 1].second + 1;
	}
	else if (bPp / 2 + 1 > ct)
	{
		return CountPatty(lv - 1, ct - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	BURGER[0] = { 0, 1 };
	for (int i = 1; i <= 50; ++i)
	{
		BURGER[i].first = BURGER[i - 1].first * 2 + 2;
		BURGER[i].second = BURGER[i - 1].second * 2 + 1;
	}

	ll N, X;
	cin >> N >> X;

	cout << CountPatty(N, X);

	return 0;
}