
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int n;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int Map[500][500];
int DP[500][500];

int Solve(int x, int y)
{
	if (DP[y][x] != 0) return DP[y][x];

    int result = 1;
    
    int out = 0;
    for (int i = 0; i < 4; i++)
    {
		int nX = x + dx[i];
		int nY = y + dy[i];
		if (nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
		if (Map[nY][nX] <= Map[y][x]) continue;

		out = max(out, Solve(nX, nY));
    }
    result += out;
	return DP[y][x] = result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    int output = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
			output = max(output, Solve(j, i));
        }
    }
    cout << output << endl;

    return 0;
}