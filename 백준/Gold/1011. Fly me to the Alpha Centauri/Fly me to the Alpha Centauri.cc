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
	
	int TC;
	cin >> TC;
	while (TC--)
	{
		int x, y;
		cin >> x >> y;
		int len = abs(x - y);
		int out = 0; int idx = 1;
		while (true)
		{
			len -= (idx * 2);
			out += 2;
			if (len <= 0)
			{
				if (len + idx <= 0)
				{
					out--;
				}
				cout << out << endl;
				break;
			}
			idx++;
		}
	}

	return 0;
}