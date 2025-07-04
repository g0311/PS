#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	stack<pair<int,int>> stk;
	vector<int> output;
	for (int i = 1; i <= n; i++)
	{
		while (!stk.empty() && stk.top().first < a[i])
		{
			stk.pop();
		}
		if (stk.empty())
		{
			output.push_back(0);
		}
		else
		{
			output.push_back(stk.top().second);
		}
		stk.push({ a[i], i});
	}

	for (int i = 0; i < n; i++)
	{
		cout << output[i] << " ";
	}

	return 0;
}