#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

int Map[301][301];
int Visited[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[N][i];
		Map[i][N] = Map[N][i];
	}
	Map[N][N] = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}

	priority_queue<pair<int, int>> q;
	q.push({ 0, N });

	ll ans = 0;
	while (!q.empty())
	{
		auto cur = q.top();
		q.pop();
		int cost = -cur.first;
		int node = cur.second;

		if (Visited[node]) continue;

		Visited[node] = 1;
		ans += cost;

		for (int i = 0; i <= N; i++)
		{
			if (Visited[i]) continue;
			q.push({ -Map[node][i], i });
		}
	}
	cout << ans << endl;

	return 0;
}