#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int st = 0;
	int ed = arr.size() - 1;
	int min = INF;
	int minst = st, mined = ed;
	while (st < ed)
	{
		if (min > abs(arr[ed] + arr[st]))
		{
			min = abs(arr[ed] + arr[st]);
			mined = ed;
			minst = st;
		}

		if (arr[ed] + arr[st] > 0)
		{
			ed--;
		}
		else if (arr[ed] + arr[st] <= 0)
		{
			st++;
		}
	}

	cout << arr[minst] << " " << arr[mined];

	return 0;
}

