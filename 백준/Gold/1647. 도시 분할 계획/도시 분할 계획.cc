
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int Set[100001];

int Find(int a)
{
	if (Set[a] == a)
		return a;
	return Set[a] = Find(Set[a]);
}

void Union(int a, int b)
{
	if (Find(a) == Find(b))
		return;
	Set[Find(a)] = Find(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
	{
		Set[i] = i;
	}
	
	vector<tuple<int, int, int>> Edges;
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		Edges.push_back({ w, u, v });
	}
	sort(Edges.begin(), Edges.end());

	vector<int> outputs;
	int sum = 0;
	for (int i = 0; i < Edges.size(); i++)
	{
		int w = get<0>(Edges[i]);
		int u = get<1>(Edges[i]);
		int v = get<2>(Edges[i]);
		if (Find(u) != Find(v))
		{
			Union(u, v);
			sum += w;
			outputs.push_back(w);
		}
	}

	int output = INF;
	for (int i = 0; i < outputs.size(); i++)
	{
		output = min(output, sum - outputs[i]);
	}
	cout << output;

	return 0;
}