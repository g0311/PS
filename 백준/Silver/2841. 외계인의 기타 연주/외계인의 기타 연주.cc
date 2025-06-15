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

	int N, P;
	cin >> N >> P;

	int ans = 0;

	stack<int> stk[7];
	for (int i = 0; i < N; i++)
	{
		int li, pr;
		cin >> li >> pr;

		while(!stk[li].empty() && stk[li].top() > pr)
		{
			stk[li].pop();
			ans++;
		}
		if (!stk[li].empty() && stk[li].top() == pr)
			continue;

		stk[li].push(pr);
		ans++;
	}
	cout << ans;

	return 0;
}

