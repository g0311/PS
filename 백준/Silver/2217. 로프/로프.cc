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
	sort(arr.begin(), arr.end());

	int maxOutput = -1;
	for (int i = 0; i < N; i++)
	{
		maxOutput = max(maxOutput, arr[i] * (N - i));
	}
	cout << maxOutput << endl;

	return 0;
}