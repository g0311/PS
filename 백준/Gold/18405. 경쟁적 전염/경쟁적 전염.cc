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

int Map[201][201];
vector<pair<int,int>> q[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            cin >> Map[i][j];
            if (Map[i][j] != 0) 
            {
                q[Map[i][j]].push_back({ i, j });
            }
        }
    }


    queue<tuple<int, int, int>> Q;
    for (int i = 1; i <= K; i++) 
    {
        for (auto& p : q[i]) 
        {
            Q.push({ p.first, p.second, 0 });
        }
    }

    int S, X, Y;
    cin >> S >> X >> Y;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!Q.empty()) 
    {
        auto [y, x, t] = Q.front();
        Q.pop();

        if (t == S) continue;

        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx <= 0 || nx > N || ny <= 0 || ny > N || Map[ny][nx] != 0)
                continue;
            Map[ny][nx] = Map[y][x];
            Q.push({ ny, nx, t + 1 });
        }
    }

    cout << Map[X][Y] << endl;
    return 0;
}