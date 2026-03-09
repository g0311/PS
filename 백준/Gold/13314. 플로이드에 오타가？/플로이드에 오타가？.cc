#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <set>
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

	cout << 100 << endl;

	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (i == j)
			{
				cout << 0 << " ";
			}
			else if (i == 100 || j == 100)
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 100 << " ";
			}
		}
		cout << endl;
	}

    return 0;
}