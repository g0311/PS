#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<int> map[10001];
vector<int> vSize;
int DP[10001][2];
int Visit[10001];
//1: 우수, 0: 비우수

void Solve(int id)
{
	DP[id][0] = 0;
	DP[id][1] = vSize[id];
	Visit[id] = 1;
	for (int i = 0; i < map[id].size(); i++)
	{
		if (Visit[map[id][i]])
			continue;

		Solve(map[id][i]);
		DP[id][0] += max(DP[map[id][i]][0], DP[map[id][i]][1]);
		DP[id][1] += DP[map[id][i]][0];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vSize.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		vSize.push_back(a);
	}
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	Solve(1);

	cout << max(DP[1][0], DP[1][1]);

	return 0;
}