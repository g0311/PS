#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

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
	vector<pair<ll, char>> ct(10, {0,0});
	for (int i = 0; i < 10; i++)
	{
		ct[i].second = 'A' + i;
	}

	vector<bool> isF(10, false);
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		isF[str[0] - 'A'] = true;
		for (int j = 0; j < str.size(); j++)
		{
			ct[str[j] - 'A'].first += pow(10, (str.size() - j - 1));
		}
	}
	
	ll minNo = 9223372036854775807LL;
	int minId = -1;
	for (int i = 0; i < 10; i++)
	{
		if (!isF[i])
		{
			if (minNo > ct[i].first)
			{
				minNo = ct[i].first;
				minId = i;
			}
		}
	}
	if (minId != -1)
	{
		ct[minId].first = 0;
	}

	sort(ct.begin(), ct.end());
	ll ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += ct[i].first * (i);
	}
	cout << ans;

	return 0;
}

/*
9973936905
9973936905
*/