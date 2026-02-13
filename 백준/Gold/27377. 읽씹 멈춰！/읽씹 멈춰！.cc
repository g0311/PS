#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int T;
ull n, s, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> n >> s >> t;

		int thres = ceil(t / s);
		ll out = 0;
		while (n > 0)
		{
			if (n / 2 <= thres)
			{
				out += n * s;
				n = 0;
			}
			else if (n % 2 != 0)
			{
				out += s;
				--n;
			}
			else
			{
				out += t;
				n /= 2;
			}
		}

		cout << out << endl;
	}

	return 0;
}

/*
n * s < t 인 n을 찾기
n = ceil t/s

현재 위치가 2n이 되면 그냥 다 빼버리면 됨
*/