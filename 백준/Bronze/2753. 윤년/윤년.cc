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

	if (N % 4 == 0 && (N % 100 != 0 || N % 400 == 0))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
    return 0;
}
