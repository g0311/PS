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
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		pq.push(-x);
	}

	ll sum = 0;
	while (pq.size() > 1)
	{
		ll x = -pq.top();
		pq.pop();
		ll y = -pq.top();
		pq.pop();
		int s = x + y;
		pq.push(-s);
		sum += s;
	}
	cout << sum;

    return 0;
}

