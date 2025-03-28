#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long

int visited[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	queue<pair<int, pair<int, int>>>q;
	q.push({ 1,{0,0} });
	visited[0][0] = 1;
	
	while (!q.empty())
	{
		int count = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ney = y + dy[i];
			int nex = x + dx[i];
			if (nex < 0 || nex >= M || ney < 0 || ney >= N)
				continue;

			if (map[ney][nex] == '1' && visited[ney][nex] == 0)
			{
				q.push({ count + 1, {ney,nex} });
				visited[ney][nex] = count + 1;
			}
		}
	}

	cout << visited[N - 1][M - 1];

	return 0;
}