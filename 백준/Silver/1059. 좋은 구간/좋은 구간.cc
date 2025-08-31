#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int L;
	cin >> L;
	vector<int> St(L);
	for (int i = 0; i < L; i++)
	{
		cin >> St[i];
	}
	sort(St.begin(), St.end());

	int N;
	cin >> N;

	int left = 0;
	int right = 0;
	
	for (int x : St) 
	{
		if (x < N) 
		{
			left = x;
		}
		else if (x > N) 
		{
			right = x;
			break;
		}
		else 
		{
			cout << 0 << endl;
			return 0;
		}
	}

	int lCount = N - left;
	int rCount = right - N;

	cout << (lCount * rCount) - 1;


	return 0;
}
