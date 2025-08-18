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

int Map[50][50];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pair<int, int>> viruses;
vector<pair<int, int>> cur_viruses;
int N, M;

int out = INF;

int CountOutput(vector<pair<int,int>> v)
{
    int empty = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (Map[i][j] == 0) empty++;
        }
    }
    if (empty == 0) return 0;

    int dist[50][50];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    for (auto [x, y] : v)
    {
        dist[y][x] = 0;
        q.push({ x, y });
    }

    int fill = 0;
    int maxTime = 0;

    while (!q.empty()) 
    {
        auto [x, y] = q.front(); q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (Map[ny][nx] == 1) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ nx, ny });

            if (Map[ny][nx] == 0) 
            {
                fill++;
                maxTime = max(maxTime, dist[ny][nx]);
            }
        }
    }

    if (fill != empty) return -1;
    return maxTime;
}

void DFS(int id, int ct)
{
	if (ct == M)
	{
        int curOut = CountOutput(cur_viruses);
        if (curOut != -1)
        {
            out = min(out, curOut);
        }
        return;
	}

	for (int i = id; i < viruses.size(); i++)
	{
		cur_viruses.push_back(viruses[i]);
		DFS(i + 1, ct + 1);
		cur_viruses.pop_back();
	}

    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)
			{
				viruses.push_back({ j, i });
			}
		}
	}

    DFS(0, 0);

    if (out == INF)
        cout << -1 << endl;
    else
		cout << out << endl;

    return 0;
}
