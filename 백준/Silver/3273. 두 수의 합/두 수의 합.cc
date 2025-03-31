#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
//정렬 가능, 명확한 기준 존재 (모든 경우의 수를 파악하지 않아도 되게 함)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int x;
	cin >> x;
	int st = 0; int ed = n - 1;
	int ct = 0;
	while (st < ed)
	{
		if (arr[st] + arr[ed] < x)
		{
			st++;
		}
		else if(arr[st] + arr[ed] > x)
		{
			ed--;
		}
		else
		{
			ct++;
			st++;
		}
	}
	cout << ct;

	return 0;
}
