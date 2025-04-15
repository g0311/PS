#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> rels(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> rels[i].first >> rels[i].second;
	}

	vector<int> DP(N + 2, 0);
	for (int i = N; i > 0; i--)
	{
		int availNexDate = rels[i].first + i - 1;
		int getPoint = rels[i].second;

		if (availNexDate >= N + 1)
		{
			DP[i] = DP[i + 1];
		}
		else
		{
			DP[i] = max(DP[i + 1], DP[availNexDate + 1] + getPoint);
		}
	}
	cout << DP[1];


	return 0;
}

/*
1 3 2 4
3 2 5 10

*/