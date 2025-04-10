
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define INF 2e9

string Map[3001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> Map[i];
        for (int j = 0; j < m; j++)
        {
            if (Map[i][j] == '2')
            {
                x = j;
                y = i;
            }
        }
    }

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	queue<pair<int, pair<int,int>>> q;
    q.push({ 0, { y,x } });
    Map[y][x] = '1';
    while (!q.empty())
    {
		int curY = q.front().second.first;
		int curX = q.front().second.second;
		int curD = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
			int nexY = curY + dy[i];
			int nexX = curX + dx[i];
			if (nexY < 0 || nexY >= n || nexX < 0 || nexX >= m) continue;
            
            if (Map[nexY][nexX] != '1')
			{
                if (Map[nexY][nexX] == '3' ||
                    Map[nexY][nexX] == '4' ||
                    Map[nexY][nexX] == '5')
                {
                    cout << "TAK" << endl << curD + 1;
                    return 0;
                }
                q.push({ curD + 1 ,{ nexY,nexX } });
                Map[nexY][nexX] = '1';
			}
        }
    }
	cout << "NIE" << endl;

    return 0;
}