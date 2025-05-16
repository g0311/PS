#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (x1 == x2)
	{
		int minY = min(y1, y2);
		int maxY = max(y1, y2);
		if (x2 == x3 && y3 > minY && y3 < maxY)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if (y1 == y2)
	{
		int minX = min(x1, x2);
		int maxX = max(x1, x2);
		if (y2 == y3 && x3 > minX && x3 < maxX)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		cout << 1 << endl;
	}

	return 0;
}
