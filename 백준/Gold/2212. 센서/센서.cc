#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
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

	int N, K;
	cin >> N >> K;

	if (N <= K || N == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> len(N);
	for (int i = 0; i < N; i++)
	{
		cin >> len[i];
	}
	sort(len.begin(), len.end());
	vector<int> ans;
	for (int i = 1; i < N; i++)
	{
		ans.push_back(len[i] - len[i - 1]);
	}
	sort(ans.begin(), ans.end());

	int output = 0;
	for (int i = 0; i < ans.size() - (K - 1); i++)
	{
		output += ans[i];
	}
	cout << output << endl;

	return 0;
}
/*
1 3 6 6 7 9
 2 3 0 1 2

*/