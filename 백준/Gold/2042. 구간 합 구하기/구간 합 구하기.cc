#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

ll N, M, K;
ll arr[1'000'000];
ll tree[4'000'004];

void init(ll cur, ll st, ll ed)
{
	if (st == ed)
	{
		tree[cur] = arr[st];
	}
	else
	{
		init(cur * 2, st, (st + ed) / 2);
		init(cur * 2 + 1, (st + ed) / 2 + 1, ed);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}
}

void change(ll cur, ll st, ll ed, ll id, ll val)
{
	if (id < st || id > ed)
		return;
	if (st == ed)
	{
		arr[id] = val;
		tree[cur] = val;
		return;
	}
	change(cur * 2, st, (st + ed) / 2, id, val);
	change(cur * 2 + 1, (st + ed) / 2 + 1, ed, id, val);
	tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

ll find(ll cur, ll st, ll ed, ll lef, ll rig)
{
	if (lef > ed || rig < st)
		return 0;
	if (lef <= st && rig >= ed)
		return tree[cur];
	
	ll sum = 0;
	sum += find(cur * 2, st, (st + ed) / 2, lef, rig);
	sum += find(cur * 2 + 1, (st + ed) / 2 + 1, ed, lef, rig);
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		ll o, a, b;
		cin >> o >> a >> b;

		if (o == 1)
		{
			change(1, 0, N - 1, a - 1, b);
		}
		else
		{
			cout << find(1, 0, N - 1, a - 1, b - 1) << endl;
		}
	}

	return 0;
}