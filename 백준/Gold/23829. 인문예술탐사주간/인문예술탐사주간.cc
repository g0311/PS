#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	vector<ll> trs(N);
	for (int i = 0; i < N; i++)
	{
		cin >> trs[i];
	}
	sort(trs.begin(), trs.end());

	vector<ll> trsSum(N + 1);
	trsSum[0] = 0;
	for (int i = 0; i < N; i++)
	{
		trsSum[i + 1] = trsSum[i] + trs[i];
	}

	for (int i = 0; i < Q; i++)
	{
		int pos;
		cin >> pos;

		ll result = 0;
		auto it = lower_bound(trs.begin(), trs.end(), pos);
		int id = it - trs.begin();

		result += (1ll * pos * id) - trsSum[id];
		result += (trsSum[N] - trsSum[id]) - (1ll * pos * (N - id));
		cout << result << endl;
	}
	return 0;
}
