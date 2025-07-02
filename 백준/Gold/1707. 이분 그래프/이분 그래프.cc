#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int v, e;
		cin >> v >> e;

		vector<vector<int>> adj(v + 1);
		for (int i = 0; i < e; i++)
		{
			int u, w;
			cin >> u >> w;
			adj[u].push_back(w);
			adj[w].push_back(u);
		}
		
		vector<int> visited(v + 1, 0);
		queue<int> q;
		bool isTrue = true;
		for (int start_node = 1; start_node <= v; ++start_node) 
		{
			if (visited[start_node] == 0)
			{
				q.push(start_node);
				visited[start_node] = 1;
				while (!q.empty())
				{
					int node = q.front();
					q.pop();
					for (int neighbor : adj[node])
					{
						if (visited[node] == -1)
						{
							if (visited[neighbor] == 0)
							{
								visited[neighbor] = 1;
								q.push(neighbor);
							}
							else if (visited[neighbor] == -1)
							{
								isTrue = false;
								break;
							}
						}
						else if (visited[node] == 1)
						{
							if (visited[neighbor] == 0)
							{
								visited[neighbor] = -1;
								q.push(neighbor);
							}
							else if (visited[neighbor] == 1)
							{
								isTrue = false;
								break;
							}
						}
					}
					if (!isTrue) break;
				}
			}
		}

		if (isTrue)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}