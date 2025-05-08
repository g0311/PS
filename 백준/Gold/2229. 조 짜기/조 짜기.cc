#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Value[1001][1001];
int DP[1001][1001];

int Solve(int st, int ed)
{
	if (DP[st][ed] != -1)
		return DP[st][ed];

	int output = Value[st][ed];
	for (int i = st; i < ed; i++)
	{
		output = max(output, Solve(st, i) + Solve(i + 1, ed));
	}
	return DP[st][ed] = output;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int>arr(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int minD = arr[i];
		int maxD = arr[i];
		for (int j = i; j <= N; j++)
		{
			minD = min(minD, arr[j]);
			maxD = max(maxD, arr[j]);
			Value[i][j] = maxD - minD;
		}
	}

	memset(DP, -1, sizeof(DP));
	cout << Solve(1, N);

	return 0;
}
