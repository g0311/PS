#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

pair<int, int> DP[46];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	DP[1] = { 0,1 };
	for (int i = 2; i <= 45; i++)
	{
		DP[i] = { DP[i - 1].second, DP[i - 1].first + DP[i - 1].second };
	}

	int K;
	cin >> K;

	cout << DP[K].first << ' ' << DP[K].second << endl;

	return 0;
}

