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
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, L;
	cin >> N >> L;
	vector<int> arr(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= N; i++)
	{
		while(!pq.empty() && pq.top().second <= i - L)
		{
			pq.pop();
		}
		pq.push({ arr[i], i });
		cout << pq.top().first << " ";
	}

	return 0;
}