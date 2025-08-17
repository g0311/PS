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

string Map[50];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Count[50][50];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}
	memset(Count, -1, sizeof(Count));

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	Count[0][0] = 0;
	while (!q.empty())
	{
		auto [x, y, cnt] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (Map[ny][nx] == '1')
			{
				if (Count[ny][nx] != -1 && Count[ny][nx] <= cnt) continue;
				q.push({ nx,ny,cnt });
				Count[ny][nx] = cnt;
			}
			else
			{
				if (Count[ny][nx] != -1 && Count[ny][nx] <= cnt + 1) continue;
				q.push({ nx,ny,cnt + 1 });
				Count[ny][nx] = cnt + 1;
			}
		}
	}
	cout << Count[N - 1][N - 1] << endl;

    return 0;
}
