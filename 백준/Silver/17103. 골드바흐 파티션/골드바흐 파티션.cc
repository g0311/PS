#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

bool IsPrime[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(IsPrime, true, sizeof(IsPrime));
	for (int i = 2; i < 1000001; i++)
	{
		if (!IsPrime[i]) continue;
		for (int j = i * 2; j < 1000001; j += i)
		{
			IsPrime[j] = false;
		}
	}

	int TC;
	cin >> TC;
	while (TC--)
	{
		int N;
		cin >> N;

		int ans = 0;
		for (int i = 2; i <= N / 2; i++)
		{
			if (IsPrime[i])
			{
				if (IsPrime[N - i])
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}