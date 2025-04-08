#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int parents[500'001];

int Find(int a)
{
	if (a == parents[a]) return a;

	return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;
	
	parents[pA] = pB;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parents[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (Find(a) == Find(b))
		{
			cout << i << endl;
			return 0;
		}
		else
		{
			Union(a, b);
		}
	}
	cout << 0 << endl;
	return 0;
}