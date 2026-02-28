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

	int N;
	cin >> N;
	
	vector<pii> Arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i].first;
		Arr[i].second = i;
	}
	sort(Arr.begin(), Arr.end());

	int out = 0;
	for (int i = 1; i < N; ++i)
	{
		if (abs(Arr[i].second - Arr[i - 1].second) > 1)
		{
			++out;
		}
	}

	cout << out;

	return 0;
}