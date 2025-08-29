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

int N;
int total = 0;
vector<int> arr(N);
vector<int> temp;
ll dp[6][6][11][11][11][11][11];

ll DFS(int ct)
{
	if (ct == total)
		return 1;

	int ret1 = temp.size() > 0 ? temp[temp.size() - 1] : -1;
	int ret2 = temp.size() > 1 ? temp[temp.size() - 2] : -1;

	if(dp[ret1 + 1][ret2 + 1][arr[0]][arr[1]][arr[2]][arr[3]][arr[4]] != -1)
		return dp[ret1 + 1][ret2 + 1][arr[0]][arr[1]][arr[2]][arr[3]][arr[4]];

	ll ret = 0;

	for (int i = 0; i < N; i++)
	{
		if(ret1 == i || ret2 == i)
			continue;

		if (arr[i] > 0)
		{
			arr[i]--;
			temp.push_back(i);
			ret += DFS(ct + 1);
			temp.pop_back();
			arr[i]++;
		}
	}
	return dp[ret1 + 1][ret2 + 1][arr[0]][arr[1]][arr[2]][arr[3]][arr[4]] = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	arr.resize(5,0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << DFS(0) << endl;

	return 0;
}
