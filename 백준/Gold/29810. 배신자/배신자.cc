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


int N, M, X;
vector<int> adj[200005];
bool visited[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> X;

    int maxGroup = 1;
    visited[X] = true;

    int out = 0;
    for (int i = 1; i <= N; i++)
    {
        int size = 0;
        int count = 0;
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            ++size;

            while (!q.empty()) 
            {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) 
                {
                    if(v == X)
                    {
                        ++count;
                    }
                    else if (!visited[v]) 
                    {
                        visited[v] = true;
                        q.push(v);
                        ++size;
                    }
                }
            }

            if (count == 1)
            {
                out = max(out, size + 1);
            }
            else 
            {
                out = max(out, size);
            }
        }
    }
    cout << out;

    return 0;
}
/*
10101010


*/