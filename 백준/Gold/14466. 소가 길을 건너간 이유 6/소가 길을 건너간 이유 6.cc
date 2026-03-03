#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <set>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int Visited[101][101];
int CowMap[101][101];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, R;
    cin >> N >> K >> R;

    set<pair<pii, pii>> edges;
    for (int i = 0; i < R; ++i)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        edges.insert({ {r1, c1}, {r2, c2} });
        edges.insert({ {r2, c2}, {r1, c1} });
    }

    for (int i = 0; i < K; ++i)
    {
        int r, c;
        cin >> r >> c;
        CowMap[r][c] = 1;
    }

    vector<int> cows;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (!Visited[i][j])
            {
                int cowCount = 0;
                queue<pii> q;

                q.push({ i, j });
                Visited[i][j] = 1;

                while (!q.empty())
                {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    if (CowMap[r][c] == 1)
                    {
                        cowCount++;
                    }

                    for (int d = 0; d < 4; ++d)
                    {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 1 && nr <= N && nc >= 1 && nc <= N && !Visited[nr][nc])
                        {
                            if (edges.count({ {r, c}, {nr, nc} }) == 0)
                            {
                                Visited[nr][nc] = 1;
                                q.push({ nr, nc });
                            }
                        }
                    }
                }

                if (cowCount > 0)
                {
                    cows.push_back(cowCount);
                }
            }
        }
    }

    int out = 0;
    for (size_t i = 0; i < cows.size(); ++i)
    {
        for (size_t j = i + 1; j < cows.size(); ++j)
        {
            out += cows[i] * cows[j];
        }
    }
    cout << out << endl;

    return 0;
}

/*
0 0 0
0 1-1
0 0-1
*/