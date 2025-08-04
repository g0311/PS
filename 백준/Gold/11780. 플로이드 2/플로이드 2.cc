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

int dist[101][101];
int next_node[101][101];

vector<int> getPath(int from, int to) 
{
	vector<int> path;
	if (next_node[from][to] == 0) return path;
	path.push_back(from);
	while (from != to) 
	{
		from = next_node[from][to];
		path.push_back(from);
	}
	return path;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dist[i][j] = (i == j) ? 0 : INF;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c < dist[a][b]) 
		{
			dist[a][b] = c;
			next_node[a][b] = b;
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					next_node[i][j] = next_node[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (dist[i][j] == INF || i == j) 
			{
				cout << 0 << endl;
			}
			else
			{
				vector<int> path = getPath(i, j);
				cout << path.size() << ' ';
				for (int city : path)
					cout << city << ' ';
				cout << endl;
			}
		}
	}

	return 0;
}