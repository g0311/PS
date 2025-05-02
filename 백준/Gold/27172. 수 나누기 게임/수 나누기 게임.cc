
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int Cards[1'000'001];
int Output[1'000'001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		Cards[arr[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		int num = arr[i] * 2;
		while (num <= 1'000'000)
		{
			if (Cards[num] != 0)
			{
				Output[arr[i]]++;
				Output[num]--;
			}
			num += arr[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << Output[arr[i]] << " ";
	}

	return 0;
}
