#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;
	int n = max(str1.size(), str2.size());

	string output;
	int carry = 0;
	for (int i = 0; i < n; i++)
	{
		int digit1 = (i < str1.size()) ? str1[str1.size() - 1 - i] - '0' : 0;
		int digit2 = (i < str2.size()) ? str2[str2.size() - 1 - i] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		output += (sum % 10) + '0';
	}
	if (carry > 0)
	{
		output += carry + '0';
	}
	reverse(output.begin(), output.end());
	cout << output;

	return 0;
}
