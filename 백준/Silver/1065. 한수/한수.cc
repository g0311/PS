
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		bool flag = true;
		int num = i;
		int bef = -1;
		int cur = -1;
		int w = INF;
		while (num > 0)
		{
			cur = num % 10;
			if (bef == -1)
			{
				bef = cur;
			}
			else if (w == INF)
			{
				w = bef - cur;
				bef = cur;
			}
			else
			{
				if (bef - cur != w)
				{
					flag = false;
					break;
				}
			}
			num /= 10;
		}
		if (flag)
		{
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}