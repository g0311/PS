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

	int N;
	cin >> N;

	int ct = 0;
	queue<ll> q;
	for (int i = 0; i <= 9; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		ct++;
		if (ct == N)
		{
			cout << cur << endl;
			return 0;
		}

		int lastD = cur % 10;
		for (int i = 0; i < lastD; i++)
		{
			ll next = cur * 10 + i;
			q.push(next);
		}
	}

	cout << -1 << endl;
    return 0;
}

/*

*/