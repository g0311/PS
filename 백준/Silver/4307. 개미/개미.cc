#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

vector<pair<int, int>> edges[5000];
int dist[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int l, n;
		cin >> l >> n;
		vector<int> ants(n);
		for (int i = 0; i < n; i++)
		{
			cin >> ants[i];
		}
		sort(ants.begin(), ants.end());
		int minOutput = 0;
		for (int i = 0; i < n; i++)
		{
			minOutput = max(minOutput, min(ants[i], l - ants[i]));
		}
		int maxOutput = max(l - ants[0], ants[n - 1]);
		cout << minOutput << " " << maxOutput << endl;
	}

	return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10
    1       1 1 
*/