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
	vector<ll> mArr;
	vector<ll> pArr;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		if (t <= 0)
		{
			mArr.push_back(t);
		}
		else
		{
			pArr.push_back(t);
		}
	}
	sort(mArr.begin(), mArr.end(), less<int>());
	sort(pArr.begin(), pArr.end(), greater<int>());

	ll out = 0;

	for (int i = 0; i < mArr.size(); i += 2)
	{
		if (i + 1 < mArr.size())
		{
			out += mArr[i] * mArr[i + 1];
		}
		else
		{
			out += mArr[i];
		}
	}

	for (int i = 0; i < pArr.size(); i += 2)
	{
		if (i + 1 < pArr.size())
		{
			if (pArr[i + 1] == 1)
			{
				out += pArr[i] + pArr[i + 1];
			}
			else
			{
				out += pArr[i] * pArr[i + 1];
			}
		}
		else
		{
			out += pArr[i];
		}
	}

	cout << out;

	return 0;
}
/*
-3 -1 1 3 5 5

*/