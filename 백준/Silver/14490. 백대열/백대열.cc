#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b; char c;
	cin >> a >> c >> b;

	int minNo = min(a, b);
	for (int i = minNo; i > 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
			break;
		}
	}
	cout << a << ":" << b;

	return 0;
}
