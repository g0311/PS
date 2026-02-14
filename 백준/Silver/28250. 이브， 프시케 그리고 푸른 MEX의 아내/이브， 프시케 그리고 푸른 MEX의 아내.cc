#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	ll ct_0 = 0;
	ll ct_1 = 0;
	ll ct_else = 0;
	for (int i = 0; i < N; ++i)
	{
		int val;
		cin >> val;
		if (val == 0)
			++ct_0;
		else if (val == 1)
			++ct_1;
		else
			++ct_else;
	}

	ll out = 0;
	out += (ct_0 * (ct_0 - 1)) / 2;
	out += (ct_0 * ct_1 * 2);
	out += (ct_0 * ct_else);

	cout << out;

	return 0;
}
