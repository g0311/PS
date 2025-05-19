#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int DP[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> mem(N + 1); mem[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> mem[i];
	}
	vector<int> value(N + 1); value[0] = 0;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> value[i];
		sum += value[i];
	}

	//메모리 m을 가방에 담아야함
	//DP[i][j] => i번째 app을 감안하고 j비용 썼을때 얻을 수 있는 최대 메모리
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			DP[i][j] = DP[i - 1][j];
			if (j - value[i] >= 0)
			{
				DP[i][j] = max(DP[i][j], DP[i - 1][j - value[i]] + mem[i]);
			}
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (DP[N][i] >= M)
		{
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
