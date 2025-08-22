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

	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1);

	arr[0] = 0;
	int maxVal = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		maxVal = max(maxVal, arr[i]);
		arr[i] += arr[i - 1];
	}

	int st = maxVal;
	int ed = arr[N];
	while (st < ed)
	{
		int mid = (st + ed) / 2;
		int ct = 0;

		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += arr[i] - arr[i - 1];
			if (sum > mid)
			{
				ct++;

				if (ct > M)
					break;

				sum = arr[i] - arr[i - 1];
			}
		}
		ct++;

		if (ct > M)
		{
			st = mid + 1;
		}
		else if (ct <= M)
		{
			ed = mid;
		}
	}

	cout << ed << endl;

	return 0;
}