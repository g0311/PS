#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

int DP[50001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	DP[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		DP[i] = i;
		for (int j = 1; j*j <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	cout << DP[N] << endl;
	return 0;
}