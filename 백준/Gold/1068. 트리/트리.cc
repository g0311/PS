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

int parent[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	set<int> nLeaps;
	for (int i = 0; i < N; i++)
	{
		cin >> parent[i];
	}
	int target;
	cin >> target;
	parent[target] = -2;

	for (int i = 0; i < N; i++)
	{
		nLeaps.insert(parent[i]);
	}
	int out = 0;
	for (int i = 0; i < N; i++)
	{
		if (nLeaps.find(i) != nLeaps.end())
			continue;

		int curN = parent[i];
		while (true)
		{
			if (curN == -1 || curN == -2)
				break;

			curN = parent[curN];
		}
		if (curN == -1)
			out++;
	}
	cout << out << endl;

    return 0;
}

