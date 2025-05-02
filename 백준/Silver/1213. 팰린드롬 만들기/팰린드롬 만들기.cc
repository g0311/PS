
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
#define INF 1'000'000'000

int Map['Z' + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		Map[str[i]]++;
	}

	bool pFlag = false;
	char pChar = -1;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (Map[i] % 2 == 1)
		{
			if (!pFlag)
			{
				pFlag = true;
				Map[i]--;
				pChar = i;
			}
			else
			{
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}

	string ans = "";
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (Map[i] % 2 == 0)
		{
			for (int j = 0; j < Map[i] / 2; j++)
			{
				ans += i;
			}
		}
	}

	cout << ans;
	if (pChar != -1)
		cout << pChar;
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
