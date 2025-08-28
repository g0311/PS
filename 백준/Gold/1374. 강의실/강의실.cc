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
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		int st = arr[i].first;
		int ed = arr[i].second;

		if (!pq.empty() && pq.top() <= st)
		{
			pq.pop();
		}
		pq.push(ed);
	}

	cout << pq.size() << endl;

	return 0;
}
