#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> Pos;
	vector<int> Neg;
	for (int i = 0; i < N; i++)
	{
		int pos;
		cin >> pos;
		if (pos >= 0)
		{
			Pos.push_back(pos);
		}
		else
		{
			pos = -pos;
			Neg.push_back(pos);
		}
	}
	sort(Pos.begin(), Pos.end());
	sort(Neg.begin(), Neg.end());

	int ans = 0;
	for (int i = Pos.size() - 1; i >= 0; i -= M)
	{
		ans += Pos[i] * 2;
	}
	for (int i = Neg.size() - 1; i >= 0; i -= M)
	{
		ans += Neg[i] * 2;
	}
	int maxPos = 0, maxNeg = 0;
	if (!Pos.empty())
	{
		maxPos = Pos[Pos.size() - 1];
	}if (!Neg.empty())
	{
		maxNeg = Neg[Neg.size() - 1];
	}
	ans -= max(maxPos, maxNeg);

	cout << ans;


	return 0;
}