#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1);
	arr[0] = 0;
	cin >> arr[1];
	for (int i = 2; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int st = 1, ed = 1;
	int curSum = 0;
	int output = 0;
	while (ed <= N)
	{
		curSum = arr[ed] - arr[st - 1];
		if (curSum > M)
		{
			st++;
		}
		else if (curSum < M)
		{
			ed++;
		}
		else
		{
			output++;
			ed++;
		}
	}

	cout << output;
	return 0;
}
