#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<int> output;
	for (int i = 0; i < N; i++)
	{
		auto iter = lower_bound(output.begin(), output.end(), arr[i]);
		if (iter == output.end())
		{
			output.push_back(arr[i]);
		}
		else
		{
			(*iter) = arr[i];
		}
	}
	cout << output.size();

	return 0;
}
/*
aababbc 7
 adaabc 6

*/