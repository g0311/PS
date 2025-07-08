#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

vector<string> map;
bool visited[250][250];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r, c;
	cin >> r >> c;
	map.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	int sAns = 0;
	int wAns = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visited[i][j] || map[i][j] == '#')
				continue;
			int sCount = 0, wCount = 0;
			if (map[i][j] == 'o') sCount++;
			else if (map[i][j] == 'v') wCount++;

			visited[i][j] = true;
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
					{
						if (abs(dx) + abs(dy) != 1) continue;
						int nx = x + dx, ny = y + dy;
						if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || map[nx][ny] == '#')
							continue;

						visited[nx][ny] = true;
						if (map[nx][ny] == 'o') sCount++;
						else if (map[nx][ny] == 'v') wCount++;
						q.push({ nx, ny });
					}
				}
			}
			if (sCount > wCount) {
				sAns += sCount;
			}
			else {
				wAns += wCount;
			}
		}
	}
	cout << sAns << " " << wAns << endl;

	return 0;
}