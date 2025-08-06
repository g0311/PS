#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int M;
	cin >> M;

	int st = 0;
	int ed = arr[arr.size() - 1];
	int ans = 0;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		int ct = 0;
		for (auto i : arr)
		{
			if (i < mid)
			{
				ct += i;
			}
			else
			{
				ct += mid;
			}
		}
		if (ct > M)
		{
			ed = mid - 1;
		}
		else
		{
			ans = mid;
			st = mid + 1;
		}
	}
	cout << ans;

	return 0;
}