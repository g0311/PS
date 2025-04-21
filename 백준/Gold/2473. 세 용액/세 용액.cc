
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 5'000'000'000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<ll> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	ll min = INF;
	vector<int> output(3);
	for (int i = 0; i < N; i++)
	{
		ll temp = arr[i];
		int st = 0; int ed = N - 1;
		while (st < ed)
		{
			if (st == i || ed == i)
			{
				st = st == i ? st + 1 : st;
				ed = ed == i ? ed - 1 : ed;
				continue;
			}

			ll sum = temp + arr[st] + arr[ed];
			if (abs(sum) < abs(min))
			{
				min = sum;
				output[0] = i;
				output[1] = st;
				output[2] = ed;
			}
			if (sum < 0)
			{
				st++;
			}
			else if (sum >= 0)
			{
				ed--;
			}
		}
	}

	sort(output.begin(), output.end());
	cout << arr[output[0]] << " " << arr[output[1]] << " " << arr[output[2]] << endl;

	return 0;
}
/*
  0 1 2 3 4 5 6
1 1 1 1 1 1 1 1
2 1 2 3 4 5 6 7
3 1 3 6 10
4 1 4
5 1 5
6 1 6

1111 112 211 22
*/