#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<int> Grp[2001];
bool Visited[2001];

bool DFS(int idx, int cnt)
{
	if (cnt == 5)
		return true;

	for (int i = 0; i < Grp[idx].size(); i++)
	{
		if (Visited[Grp[idx][i]])
			continue;

		Visited[Grp[idx][i]] = true;
		if (DFS(Grp[idx][i], cnt + 1))
		{
			return true;
		}
		Visited[Grp[idx][i]] = false;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Grp[a].push_back(b);
		Grp[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		Visited[i] = true;
		if (DFS(i, 1))
		{
			cout << 1;
			return 0;
		}
		Visited[i] = false;
	}
	cout << 0;


	return 0;
}
