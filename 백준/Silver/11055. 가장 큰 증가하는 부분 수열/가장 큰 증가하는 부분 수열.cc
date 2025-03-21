#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'

int DP[1000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		DP[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				DP[i] = max(DP[i], DP[j] + arr[i]);
			}
		}
	}

	int output = 0;
	for (int i = 0; i < N; i++)
	{
		output = max(output, DP[i]);
	}
	cout << output;

	return 0;
}