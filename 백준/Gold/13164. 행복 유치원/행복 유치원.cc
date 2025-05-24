#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<ll> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<ll> cost(N - 1);
	for (int i = 1; i < N; i++)
		cost[i - 1] = arr[i] - arr[i - 1];
	sort(cost.begin(), cost.end());
	ll ans = 0;
	for (int i = 0; i < N - K; i++)
		ans += cost[i];
	cout << ans << endl;

	return 0;
}
