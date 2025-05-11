#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> DP1(N);
	vector<int> DP2(N);
	for (int i = 0; i < N; i++)
	{
		DP1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				DP1[i] = max(DP1[i], DP1[j] + 1);
			}
		}
	}

	int output = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		DP2[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				DP2[i] = max(DP2[i], DP2[j] + 1);
			}
		}
		output = max(output, DP1[i] + DP2[i] - 1);
	}
	cout << output;

	return 0;
}
