#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

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
	
	vector<int> DP(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		DP[a] = DP[a - 1] + 1;
	}

	int output = -1;
	for (int i = 1; i <= N; i++)
	{
		output = max(output, DP[i]);
	}
	cout << N - output;

	return 0;
}
