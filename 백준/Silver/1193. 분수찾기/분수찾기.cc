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

	int N;
	cin >> N;

	int ct = 1;
	while (ct < N)
	{
		N -= ct;
		ct++;
	}

	if(ct % 2 == 0)
	{
		cout << N << '/' << ct - N + 1 << endl;
	}
	else
	{
		cout << ct - N + 1 << '/' << N << endl;
	}

	return 0;
}
