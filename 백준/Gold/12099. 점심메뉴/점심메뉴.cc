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
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	vector<pii> menu(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> menu[i].first >> menu[i].second;
	}
	sort(menu.begin(), menu.end());

	for (int i = 0; i < Q; ++i)
	{
		int u, v, x, y;
		cin >> u >> v >> x >> y;

		auto it_st = lower_bound(menu.begin(), menu.end(), make_pair(u,0));
		auto it_ed = upper_bound(menu.begin(), menu.end(), make_pair(v, 2'000'000'000));

		vector<pii> sub_vec(it_st, it_ed);

		sort(sub_vec.begin(), sub_vec.end(), [](const pii& a, const pii& b) {
				return a.second < b.second;
			});

		auto ans_st = lower_bound(sub_vec.begin(), sub_vec.end(), make_pair(-1, x), [](const pii& a, const pii& b) {
				return a.second < b.second;
			});
		auto ans_ed = upper_bound(sub_vec.begin(), sub_vec.end(), make_pair(-1, y), [](const pii& a, const pii& b) {
				return a.second < b.second;
			});
		
		cout << distance(ans_st, ans_ed) << endl;
	}

	return 0;
}
