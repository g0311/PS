
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int R, C;
vector<string> str;

int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

int output = 0;
bool Solve(int x, int y)
{
    if (x == C - 1)
    {
        output++;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
		int nX = x + dx[i];
		int nY = y + dy[i];
        if (nX < 0 || nX >= C || nY < 0 || nY >= R || str[nY][nX] == 'x')
            continue;

        str[nY][nX] = 'x';
        if (Solve(nX, nY))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> R >> C;
    str.resize(R);
	for (int i = 0; i < R; i++)
	{
		cin >> str[i];
	}

    for (int i = 0; i < R; i++)
    {
		if (str[i][0] == 'x')
			continue;

        str[i][0] = 'x';
		Solve(0, i);
    }

	cout << output << endl;

    return 0;
}