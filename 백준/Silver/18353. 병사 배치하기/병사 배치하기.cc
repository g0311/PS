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
#define INF 1e9

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
	reverse(arr.begin(), arr.end());
	vector<int> out;
	for (int i = 0; i < N; i++)
	{
		auto iter = lower_bound(out.begin(), out.end(), arr[i]);
		if (iter == out.end())
		{
			out.push_back(arr[i]);
		}
		else
		{
			*iter = arr[i];
		}
	}
	cout << arr.size() - out.size() << endl;

	return 0;
}