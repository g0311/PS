#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	stack<char> stk;
	for (char c : str)
	{
		stk.push(c);
		if (stk.size() >= 4)
		{
			char d = stk.top();
			stk.pop();
			char c = stk.top();
			stk.pop();
			char b = stk.top();
			stk.pop();
			char a = stk.top();
			stk.pop();
			if (a == 'P' && b == 'P' && c == 'A' && d == 'P')
			{
				stk.push('P');
			}
			else
			{
				stk.push(a);
				stk.push(b);
				stk.push(c);
				stk.push(d);
			}
		}
	}
	if(stk.size() == 1 && stk.top() == 'P')
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;

	return 0;
}
