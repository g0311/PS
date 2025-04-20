
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'003

int Visited[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;
    vector<string> Map(r);
    for (int i = 0; i < r; i++)
    {
        cin >> Map[i];
    }

    int dx[] = { -1,0,1,0 };
    int dy[] = { 0,-1,0,1 };

    int output = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (Map[i][j] != 'L')
                continue;

            int curOutput = 0;
            memset(Visited, -1, sizeof(Visited));
            queue<pair<int, int>> q;
            q.push({ i,j });
            Visited[i][j] = 0;
            while (!q.empty())
            {
                int curY = q.front().first;
                int curX = q.front().second;
                int curD = Visited[curY][curX];
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nexY = curY + dy[k];
                    int nexX = curX + dx[k];
                    if (nexX < 0 || nexX >= c || nexY < 0 || nexY >= r)
                        continue;
                    if (Visited[nexY][nexX] != -1)
                        continue;
                    if (Map[nexY][nexX] != 'L')
                        continue;

                    q.push({ nexY, nexX });
                    Visited[nexY][nexX] = curD + 1;
                    curOutput = max(curOutput, Visited[nexY][nexX]);
                }
            }
            output = max(output, curOutput);
        }
    }
    cout << output;

    return 0;
}