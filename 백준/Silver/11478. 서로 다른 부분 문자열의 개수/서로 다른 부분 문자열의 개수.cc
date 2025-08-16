#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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

	string s;
	cin >> s;

	set<string> sts;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			string temp = s.substr(i, j + 1);
			sts.insert(temp);
		}
	}
	cout << sts.size();

    return 0;
}
