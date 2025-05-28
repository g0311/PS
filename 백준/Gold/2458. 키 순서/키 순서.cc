#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

vector<int> Map[501];
vector<int> Smaller[501];
vector<int> Greater[501];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		queue<int> q;
		bool visited[501] = { false };
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			for (int next : Map[current])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push(next);
					Smaller[next].push_back(i);
					Greater[i].push_back(next);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Smaller[i].size() + Greater[i].size() == N - 1)
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}