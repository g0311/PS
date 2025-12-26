#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int Parents[300'001];

int Find(int a)
{
	if (Parents[a] == a)
	{
		return a;
	}

	return Parents[a] = Find(Parents[a]);
}

void Union(int a, int b)
{
	int aParent = Find(a);
	int bParent = Find(b);

	if (aParent == bParent)
		return;

	Parents[aParent] = bParent;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		Parents[i] = i;
	}

	for (int i = 0; i < N - 2; ++i)
	{
		int st, ed;
		cin >> st >> ed;

		Union(st, ed);
	}

	int a = Find(1);
	int b = 0;
	for (int i = 2; i <= N; i++)
	{
		if (Find(i) != a)
		{
			b = Find(i);
			break;
		}
	}

	cout << a << " " << b;
	
	return 0;
}