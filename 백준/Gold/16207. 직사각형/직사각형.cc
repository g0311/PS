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

	vector<ll> Arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
	}
	sort(Arr.begin(), Arr.end(), greater<int>());

	ll firstNo = -1;
	vector<ll> outArr;
	for (int i = 0; i < N; ++i)
	{
		if (firstNo == -1)
		{
			firstNo = Arr[i];
		}
		else if(Arr[i] == firstNo || Arr[i] == firstNo +1 || Arr[i] == firstNo - 1)
		{
			outArr.push_back(min(Arr[i], firstNo));
			firstNo = -1;
		}
		else
		{
			firstNo = Arr[i];
		}
	}

	ll out = 0;
	for (int i = 1; i < outArr.size(); i += 2)
	{
		out += outArr[i] * outArr[i - 1];
	}
	cout << out;

	return 0;
}

/*
10 6 6 6 5 4 4 4 3
6 5 4 3
*/