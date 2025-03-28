#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;
	vector<int> arr(N + 1);
	arr[0] = 0;;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int st = 0, ed = 1;
	int output = 100001;
	while (st < ed && ed <= N)
	{
		if (arr[ed] - arr[st] >= S)
		{
			output = min(output, ed - st);
			st++;
		}
		else
		{
			ed++;
		}
	}

	if (output == 100001)
		cout << 0;
	else
		cout << output;

	return 0;
}

/*
0 5 6 9 14 24 31 35 44 46 54
0 54
0 46
0 44
0 14
5 14

*/