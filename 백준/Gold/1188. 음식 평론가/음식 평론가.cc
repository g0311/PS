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

	int N, M;
	cin >> N >> M;
	int X = N * M;

	int out = 0;
	for (int i = 0; i < X; i += N)
	{
		if (i % M != 0)
		{
			out++;
		}
	}
	cout << out << endl;

    return 0;
}