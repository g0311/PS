#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n;
		cin >> n;
		vector<pair<int,int>> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end());
		int ans = 0;
		int curMin = INF;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].second < curMin)
			{
				curMin = arr[i].second;
				ans++;
			}
			else
			{
				curMin = min(curMin, arr[i].second);
			}
		}
		cout << ans << endl;
	}

	return 0;
}

/*
3 2
1 4
4 1
2 3
5 5

1 4
2 3
3 5
4 1
5 2
*/