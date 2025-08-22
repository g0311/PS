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

	vector<pair<int, int>> arr(8);
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i].first;
		arr[i].first *= -1;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end());

	int sum = 0;
	vector<int> arr2(5);
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i].first;
		arr2[i] = arr[i].second;
	}
	sort(arr2.begin(), arr2.end());
	cout << -sum << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}

	return 0;
}