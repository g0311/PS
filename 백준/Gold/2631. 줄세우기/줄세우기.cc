
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int DP[201];

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
		DP[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(arr[i] > arr[j])
				DP[i] = max(DP[i], DP[j] + 1);
		}
	}
	int output = 0;
	for (int i = 0; i < N; i++)
	{
			output = max(DP[i], output);
	}
	cout << N - output << endl;

	return 0;
}