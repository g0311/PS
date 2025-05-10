#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007
#define MOD 100000

int DP[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	DP[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			int temp = 0;
			temp += j * (i - j);
			temp += (DP[j] + DP[i - j]);
			DP[i] = max(DP[i], temp);
		}
	}

	cout << DP[N];

	return 0;
}
