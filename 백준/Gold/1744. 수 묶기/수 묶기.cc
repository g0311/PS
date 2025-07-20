#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> minus, plus;
	for (int i = 0; i < N; i++) 
	{
		int x;
		cin >> x;
		if (x <= 0) minus.push_back(x);
		else plus.push_back(x);
	}
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < minus.size(); i += 2)
	{
		if (i + 1 < minus.size())
		{
			ans += max(minus[i] * minus[i + 1], minus[i] + minus[i + 1]);
		}
		else
		{
			ans += minus[i];
		}
	}
	for (int i = 0; i < plus.size(); i += 2)
	{
		if (i + 1 < plus.size())
		{
			ans += max(plus[i] * plus[i + 1], plus[i] + plus[i + 1]);
		}
		else
		{
			ans += plus[i];
		}
	}

	cout << ans;

	return 0;
}