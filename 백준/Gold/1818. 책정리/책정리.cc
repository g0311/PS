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
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<int> output;
	for (int i = 0; i < N; i++)
	{
		auto temp = lower_bound(output.begin(), output.end(), arr[i]);
		if (temp != output.end())
		{
			*temp = arr[i];
		}
		else
		{
			output.push_back(arr[i]);
		}
	}
	cout << N - output.size();

	return 0;
}
