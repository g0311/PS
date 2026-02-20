#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X, Y, D, T;
	cin >> X >> Y >> D >> T;

	double Dist = sqrt(X * X + Y * Y);
	int n = Dist / D;

	double out = Dist;

	if (Dist >= D)
	{
		out = fmin(out, n * T + Dist - n * D);
		out = fmin(out, (n + 1) * T + (n + 1) * D - Dist);
		out = fmin(out, (n + 1) * T);
	}
	else
	{
		out = fmin(out, T + D - Dist);
		out = fmin(out, 2.f * T);
	}

	cout << fixed << setprecision(12) << out;

	return 0;
}
