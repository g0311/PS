
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

ll DP[36];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, pair<int, int>>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	}

	int output = 0;
	for (int i = 123; i <= 987; i++)
	{
		if (i % 10 == i / 10 % 10 || i % 10 == i / 100 % 10 || i / 10 % 10 == i / 100 % 10)
		{
			continue;
		}
		if (i / 100 == 0 || (i / 10) % 10 == 0 || i % 10 == 0)
		{
			continue;
		}

		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			int no = v[j].first;
			int a = v[j].second.first;
			int b = v[j].second.second;

			vector<int> curNo(3);
			curNo[0] = i / 100 % 10;
			curNo[1] = i / 10 % 10;
			curNo[2] = i % 10;

			vector<int> queNo(3);
			queNo[0] = no / 100 % 10;
			queNo[1] = no / 10 % 10;
			queNo[2] = no % 10;

			int strike = 0;
			for (int k = 0; k < 3; k++)
			{
				if (curNo[k] == queNo[k])
				{
					strike++;
				}
			}
			int ball = 0;
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					if (x != y && curNo[x] == queNo[y])
					{
						ball++;
					}
				}
			}
			if (strike != a || ball != b)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			output++;
		}
	}
	cout << output;

	return 0;
}