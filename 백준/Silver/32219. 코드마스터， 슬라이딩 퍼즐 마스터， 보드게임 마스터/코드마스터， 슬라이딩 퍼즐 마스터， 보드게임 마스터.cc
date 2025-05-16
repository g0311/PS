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

	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;

		if (r == c)
		{
			cout << "dohoon" << endl;
		}
		else
		{
			cout << "jinseo" << endl;
			int minNo = min(r, c);
			cout << minNo << " " << minNo << endl;
		}
	}

	return 0;
}
