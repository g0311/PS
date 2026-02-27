#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M, N;
	cin >> M >> N;
	
	vector<int> Arr(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
	}
	sort(Arr.begin(), Arr.end());

	int left = 1; int right = Arr[N - 1];
	int mid = -1;
	int output = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int out = 0;
		for (int i = 0; i < N; ++i)
		{
			out += (Arr[i] / mid);
		}
		if (out >= M)
		{
			left = mid + 1;
			output = max(output, mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << output;

	return 0;
}