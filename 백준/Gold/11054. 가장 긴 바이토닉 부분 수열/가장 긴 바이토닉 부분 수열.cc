#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

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
	vector<int> arr1(N);
	vector<int> arr2(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr1[i];
		arr2[i] = -arr1[i];
	}

	int output = 0;
	vector<int> DP1;
	vector<int> DP2;
	for (int i = 0; i < N; i++)
	{
		auto temp = lower_bound(DP1.begin(), DP1.end(), arr1[i]);
		if (temp != DP1.end())
		{
			*temp = arr1[i];
		}
		else
		{
			DP1.push_back(arr1[i]);
		}

		DP2.clear();
		for (int j = i; j < N; j++)
		{
			auto temp = lower_bound(DP2.begin(), DP2.end(), arr2[j]);
			if (temp != DP2.end())
			{
				*temp = arr2[j];
			}
			else
			{
				DP2.push_back(arr2[j]);
			}
		}
		output = max(output, (int)DP1.size() + (int)DP2.size() - 1);
	}
	cout << output;

	return 0;
}
