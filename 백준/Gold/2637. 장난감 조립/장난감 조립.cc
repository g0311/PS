#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<vector<pair<int, int>>> Map;
int InDegree[101];
int result[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	Map.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		Map[y].push_back({x,z});
		//y는 x를 만드는데 z개 들어간다
		InDegree[x]++;
	}
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		if (InDegree[i] == 0)
		{
			result[i][i] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto iter : Map[cur])
		{
			for (int i = 0; i <= N; i++)
			{
				result[iter.first][i] += result[cur][i] * iter.second;
			}
			InDegree[iter.first]--;
			if (InDegree[iter.first] == 0)
				q.push(iter.first);
		}
	}

	for (int i = 0; i <= N; i++)
	{
		if (result[N][i] != 0)
		{
			cout << i << " " << result[N][i] << endl;
		}
	}

	return 0;
}
//100'000