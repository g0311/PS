#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int parents[1001];
vector<pair<int, pair<int, int>>> edges;
int find(int x)
{
	if (parents[x] == x) return x;
	return parents[x] = find(parents[x]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b) parents[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, { a, b } });
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
	}
	int totalCost = 0;
	for (auto edge : edges)
	{
		int cost = edge.first;
		int a = edge.second.first;
		int b = edge.second.second;
		if (find(a) != find(b))
		{
			totalCost += cost;
			Union(a, b);
		}
	}
	cout << totalCost << endl;

	return 0;
}