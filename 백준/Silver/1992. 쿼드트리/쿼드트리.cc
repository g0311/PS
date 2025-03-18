#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define endl '\n'

string map[64]; 
int visit[64][64];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
void solve(int stX, int stY, int size)
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ stY,stX });
	visit[stY][stX] = 1;
	char curC = map[stY][stX];
	while (!q.empty())
	{
		int x = q.front().second, y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nex = x + dx[i];
			int ney = y + dy[i];

			if (nex < stX || nex >= stX + size || ney < stY || ney >= stY + size)
				continue;
			if (visit[ney][nex])
				continue;

			if (map[ney][nex] != curC)
			{
				cout << "(";
				int nSize = size / 2;
				solve(stX, stY, nSize);
				solve(stX + nSize, stY, nSize);
				solve(stX, stY + nSize, nSize);
				solve(stX + nSize, stY + nSize, nSize);
				cout << ')';
				return;
			}
			else
			{
				q.push({ ney,nex });
				visit[ney][nex] = 1;
			}
		}
	}
	cout << map[stY][stX];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	solve(0, 0, N);

	return 0;
}