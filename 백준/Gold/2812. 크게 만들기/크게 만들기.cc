#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	stack<char> stk;
	for (int i = 0; i < S.size(); i++)
	{
		if (K == 0)
		{
			stk.push(S[i]);
		}
		else
		{
			if (stk.empty())
			{
				stk.push(S[i]);
			}
			else
			{
				while (!stk.empty() && K > 0 && stk.top() < S[i])
				{
					stk.pop();
					K--;
				}
				stk.push(S[i]);
			}
		}
	}
	while (K > 0 && !stk.empty())
	{
		stk.pop();
		K--;
	}

	string output = "";
	while (!stk.empty())
	{
		output += stk.top();
		stk.pop();
	}
	reverse(output.begin(), output.end());
	cout << output << endl;

	return 0;
}