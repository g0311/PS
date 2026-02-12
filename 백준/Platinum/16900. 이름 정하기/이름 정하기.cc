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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int Fail[500'001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	int k;
	cin >> str >> k;

	for (int i = 1, j = 0; i < str.size(); ++i)
	{
		while (j && str[i] != str[j])
		{
			j = Fail[j - 1];
		}
		if (str[i] == str[j])
		{
			Fail[i] = ++j;
		}
	}
	
	ll overlap = Fail[str.size() - 1];
	ll unonverlap = str.size() - Fail[str.size() - 1];
	cout << unonverlap * k + overlap;

	return 0;
}

/*
abbababbbbababab abba
				 abba babbbbababababba
안겹: 16
겹: 4
16*2+4 36

abcabcabca
   abcabcabca
	  abcabcabca
안겹: 3 
겹: 7
3*3+7 16

안겹 * 개수 + 겹
KMP 알고리즘
*/