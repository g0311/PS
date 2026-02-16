#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> Arr(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
	}

	int cur = 0;
	int out = 0;
	int curOut = 0;
	for (int i = 1; i <= N; ++i)
	{
		curOut = 0;
		double minSlope = 1e18;
		for (int j = i - 1; j >= 1; --j)
		{
			double Slope = (double)(Arr[i] - Arr[j]) / (i - j);
			if (j == i - 1 || Slope < minSlope)
			{
				minSlope = Slope;
				++curOut;
			}
		}

		double maxSlope = -1e18;
		for (int j = i + 1; j <= N; ++j)
		{
			double Slope = (double)(Arr[j] - Arr[i]) / (j - i);
			if (j == i + 1 || Slope > maxSlope)
			{
				maxSlope = Slope;
				++curOut;
			}
		}
		out = max(out, curOut);
	}

	cout << out;

	return 0;
}
