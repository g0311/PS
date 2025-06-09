#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int E, S, M;
	cin >> E >> S >> M;

	int e = 1, s = 1, m = 1;
	int year = 1;
	while (true)
	{
		if (e == E && s == S && m == M)
			break;
		year++;
		e++; if (e == 16) e = 1;
		s++; if (s == 29) s = 1;
		m++; if (m == 20) m = 1;
	}
	cout << year << endl;
	return 0;
}