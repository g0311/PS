#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'
#define MAX 1'000'000'007

vector<int> DP[1'000'000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R;
	cin >> N >> R;

	for (int i = 1; i <= N; i++)
	{
		DP[i].push_back(1);
		for (int j = 1; j < i; j++)
		{
			int X = (DP[i - 1][j - 1] + DP[i - 1][j]) % MAX;
			DP[i].push_back(X);
		}
		DP[i].push_back(1);
	}

	cout << DP[N][R];

	return 0;
}
