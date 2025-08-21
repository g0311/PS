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

	ll st, ed, x, y;
	cin >> st >> ed >> x >> y;
	if (ed < st)
	{
		ll temp = st;
		st = ed;
		ed = temp;
	}
	if (y < 0 || y >= abs(x))
	{
		cout << "Unknwon Number" << endl;
		return 0;
	}

	if (x == 0) 
	{
		if (st <= y && y <= ed) 
		{
			cout << y << endl;
		}
		else 
		{
			cout << "Unknwon Number" << endl;
		}
		return 0;
	}

	ll ax = abs(x);
	ll stR = (st % ax + ax) % ax;
	ll diff = (y - stR + ax) % ax;

	ll Out = st + diff;
	ll Nex = Out + ax;
	if (Out > ed || Nex <= ed)
	{
		cout << "Unknwon Number" << endl;
	}
	else
	{
		cout << Out << endl;
	}

	return 0;
}