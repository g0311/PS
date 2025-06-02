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

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int st = 0, ed = 0;
	int output = 1;
	vector<int> ct(10, 0);
	ct[arr[ed]]++;
	while (st < n)
	{
		while (ed < n)
		{
			ed++;
			if (ed >= n) break;
			ct[arr[ed]]++;

			int numCt = 0;
			for (int j = 1; j <= 9; j++)
			{
				if (ct[j] > 0)
				{
					numCt++;
				}
			}

			if (numCt > 2)
			{
				ct[arr[ed]]--;
				ed--;
				output = max(output, ed - st + 1);
				break;
			}
			else
			{
				output = max(output, ed - st + 1);
			}
		}

		ct[arr[st]]--;
		st++;
	}

	cout << output;

	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 1 
1 2 2 2 1 2 3 2 2 2 2 2 2 1 1 2
*/