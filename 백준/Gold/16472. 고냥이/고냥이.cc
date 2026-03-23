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
#define MOD 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	cin >> N >> str;

	vector<int> alpha(26, 0);

	int out = 0;
	int alphaCount = 0;
	int st = 0, ed = 0;
	for (int ed = 0; ed < str.size(); ed++)
	{
		if (alpha[str[ed] - 'a'] == 0)
		{
			++alphaCount;
		}
		++alpha[str[ed] - 'a'];
		
		while (alphaCount > N)
		{
			--alpha[str[st] - 'a'];
			if (alpha[str[st] - 'a'] == 0)
			{
				--alphaCount;
			}
			++st;
		}

		out = max(out, ed - st + 1);
	}

	cout << out << endl;

	return 0;
}