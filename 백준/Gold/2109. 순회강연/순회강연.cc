#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> arr(10001);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}

	priority_queue<int>pq;
	int ans = 0;
	for (int i = 10000; i > 0; i--)
	{
		if (arr[i].size() >= 0)
		{
			for (auto x : arr[i])
			{
				pq.push(x);
			}
		}
		if(!pq.empty())
		{
			ans += pq.top(); pq.pop();
		}
	}
	cout << ans;

	return 0;
}

/*
4 100
4 90
3 3
3 2 
3 1
*/