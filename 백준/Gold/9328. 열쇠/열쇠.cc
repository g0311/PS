#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

char map[101][101];
int visited[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int h, w;
		cin >> h >> w;
		
		queue<pair<int, int>> q;
		set<int> keys;
		vector<pair<int, int>> doors;
		int ans = 0;

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
				visited[i][j] = 0;

				if (i == 1 || i == h || j == 1 || j == w)
				{
					if (map[i][j] == '.')
					{
						q.push({ i, j });
						visited[i][j] = 1;
					}
					else if (map[i][j] == '$')
					{
						q.push({ i, j });
						visited[i][j] = 1;
						ans++;
					}
					else if (map[i][j] >= 'a' && map[i][j] <= 'z')
					{
						q.push({ i, j });
						keys.insert(map[i][j]);
						visited[i][j] = 1;
					}
					else if (map[i][j] >= 'A' && map[i][j] <= 'Z')
					{
						if (keys.find(tolower(map[i][j])) != keys.end())
						{
							visited[i][j] = 1;
							q.push({ i, j });
						}
						else
						{
							doors.push_back({ i, j });
						}
					}
				}
			}
		}

		string k;
		cin >> k;
		for (int i = 0; i < k.size(); i++)
		{
			if (k[i] == '0')
				continue;
			else
				keys.insert(k[i]);
		}
		
		if (q.empty())
		{
			for (int i = 0; i < doors.size(); i++)
			{
				if (keys.find(tolower(map[doors[i].first][doors[i].second])) != keys.end())
				{
					if (visited[doors[i].first][doors[i].second] == 0)
					{
						visited[doors[i].first][doors[i].second] = 1;
						q.push({ doors[i].first, doors[i].second });
					}
				}
			}
		}
		while (!q.empty())
		{
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > w || ny < 1 || ny > h)
					continue;
				if (visited[ny][nx] == 1)
					continue;

				if (map[ny][nx] == '.')
				{
					visited[ny][nx] = 1;
					q.push({ ny, nx });
				}
				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
				{
					visited[ny][nx] = 1;
					keys.insert(map[ny][nx]);
					q.push({ ny, nx });
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z')
				{
					if (keys.find(tolower(map[ny][nx])) != keys.end())
					{
						visited[ny][nx] = 1;
						q.push({ ny, nx });
					}
					else
					{
						doors.push_back({ ny, nx });
					}
				}
				else if (map[ny][nx] == '$')
				{
					visited[ny][nx] = 1;
					ans++;
					q.push({ ny, nx });
				}
			}
			if (q.empty())
			{
				for (int i = 0; i < doors.size(); i++)
				{
					if (keys.find(tolower(map[doors[i].first][doors[i].second])) != keys.end())
					{
						if (visited[doors[i].first][doors[i].second] == 0)
						{
							visited[doors[i].first][doors[i].second] = 1;
							q.push({ doors[i].first, doors[i].second });
						}
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
