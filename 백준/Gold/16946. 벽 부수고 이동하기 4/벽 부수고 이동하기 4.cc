
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

string Map[1001];
int DP[1000001];
int visited[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> zeros;
	for(int i = 0; i < n; i++)
	{
		cin >> Map[i];
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == '0')
			{
				zeros.push_back(make_pair(i, j));
			}
		}
	}

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < zeros.size(); i++)
	{
		if (visited[zeros[i].first][zeros[i].second] != -1)
			continue;
		queue<pair<int, int>> q;
		q.push(zeros[i]);
		visited[zeros[i].first][zeros[i].second] = i;
		int output = 1;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
					continue;
				if (Map[ny][nx] == '1')
					continue;
				if (visited[ny][nx] != -1)
					continue;
				visited[ny][nx] = i;
				q.push(make_pair(ny, nx));
				output++;
			}
		}
		DP[i] = output;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == '1')
			{
				int output = 1;
				set<int> vs;
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
						continue;
					if (Map[ny][nx] == '1')
						continue;
					if (vs.find(visited[ny][nx]) != vs.end())
						continue;
					vs.insert(visited[ny][nx]);
					output += DP[visited[ny][nx]];
				}
				cout << output % 10;
			}
			else
			{
				cout << 0;
			}
		}
		cout << endl;
	}

	return 0;
}