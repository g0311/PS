#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> ct(1000001, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		ct[arr[i]]++;
	}

	vector<int> output(N, -1);
	stack<int> stk;
	for (int i = 0; i < N; i++)
	{
		while (!stk.empty() && ct[arr[i]] > ct[arr[stk.top()]])
		{
			int id = stk.top();
			stk.pop();
			output[id] = arr[i];
		}
		stk.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << output[i] << " ";
	}

	return 0;
}

