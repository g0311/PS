#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

set<pair<int, int>> DP;
set<int> out;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		vector<pair<int, int>> temp;
		temp.push_back({ arr[i], 0 });
		temp.push_back({ 0, arr[i] });
		for (auto& [left, right] : DP)
		{
			temp.push_back({ left + arr[i], right });
			temp.push_back({ left, right + arr[i] });
		}
		DP.insert(temp.begin(), temp.end());
	}

	for (auto& [left, right] : DP)
	{
		out.insert(abs(left - right));
	}

	int tc;
	cin >> tc;
	while (tc--) 
	{
		int target;
		cin >> target;
		if (out.find(target) != out.end())
		{
			cout << "Y" << " ";
		}
		else
		{
			cout << "N" << " ";
		}
	}

	return 0;
}