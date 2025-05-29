#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A[x] = i;
	}
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		arr[i] = A[x];
	}

	vector<int> output;
	for (int i = 0; i < N; i++)
	{
		int x = arr[i];
		auto out = lower_bound(output.begin(), output.end(), x);
		if (out == output.end())
		{
			output.push_back(x);
		}
		else
		{
			*out = x;
		}
	}
	cout << output.size();

	return 0;
}

/*
A: 1 2 4 7 8 9 6 3 5
B: 2 4 6 8 1 3 5 7 9
   2 3 7 5 1 8 9 4 6
*/