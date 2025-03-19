#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int N;
vector<pair<int, int>> ps;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		ps.push_back({ min(x,y), max(x,y)});
	}
	sort(ps.begin(), ps.end());

	vector<int>DP(N, 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (ps[j].second <= ps[i].second)
				DP[i] = max(DP[i], DP[j] + 1);
		}
	}

	int output = 0;
	for (int i = 0; i < N; i++)
	{
		output = max(DP[i], output);
	}

	cout << output;

	return 0;
}