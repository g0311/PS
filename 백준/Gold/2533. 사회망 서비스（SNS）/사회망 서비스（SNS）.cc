#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

vector<int> Map[1'000'001];
pair<int, int> DP[1'000'001]; //내가 얼리 어댑터 / 내가 얼리 어댑터가 아닐 때

int DFS(int node, int parent)
{
	if (DP[node].first != -1) return DP[node].first;

	DP[node].first = 1; DP[node].second = 0;
	for (int i = 0; i < Map[node].size(); i++)
	{
		int next = Map[node][i];
		if (next == parent) continue;
		DP[node].second += DFS(next, node);
		DP[node].first += min(DP[next].first, DP[next].second);
	}

	return DP[node].first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a].push_back(b);
		Map[b].push_back(a);
	}

	memset(DP, -1, sizeof(DP));
	DFS(1, -1);
	cout << min(DP[1].first, DP[1].second) << endl;

	return 0;
}
