#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int DP[4][50001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++) 
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int K;
	cin >> K;

	vector<int> sum(N + 1, 0);
	for (int i = K; i <= N; i++) 
	{
		sum[i] = arr[i] - arr[i - K];
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = K; j <= N; j++)
		{
			DP[i][j] = max(DP[i][j - 1], DP[i - 1][j - K] + sum[j]);
		}
	}

	cout << DP[3][N] << endl;

	return 0;
}