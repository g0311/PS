#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> value(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> value[i];
	}

	vector<int> DP(N + 1, INF);
	DP[0] = 0;
	DP[1] = value[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - j] + value[j]);
		}
	}

	cout << DP[N];

	return 0;
}

/*
 1 2 3
 1 3 6

*/