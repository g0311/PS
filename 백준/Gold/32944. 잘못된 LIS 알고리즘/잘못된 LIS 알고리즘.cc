#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	if (n - m < 1)
	{
		cout << -1;
		return 0;
	}
	vector<int> result;
	for (int i = 1; i < k; i++)
	{
		result.push_back(i);
	}
	result.push_back(n);
	for (int i = n - 1; i > m; i--)
	{
		result.push_back(i);
	}
	for (int i = k; i <= m; i++)
	{
		result.push_back(i);
	}

	for (auto x : result)
	{
		cout << x << " ";
	}

	return 0;
}
/*
8 6 3
1 2 3 4 5 6 7 8
1 2 8 
3 4 5 6 7
1 2 8 4 5 6 7 3
1 2 8 7 3 4 5 6
*/