#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

vector<tuple<double, int, int>> edges;

int parent[1'001];

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<pair<int,int>> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int x1 = arr[i].first, y1 = arr[i].second;
			int x2 = arr[j].first, y2 = arr[j].second;

			double dist = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
			edges.push_back(make_tuple(dist, i, j));
		}
	}

	sort(edges.begin(), edges.end());

	double result = 0;
	for (auto& edge : edges)
	{
		double dist;
		int a, b;
		tie(dist, a, b) = edge;
		if (Find(a) != Find(b))
		{
			result += sqrt(dist);
			Union(a, b);
		}
	}
	cout << fixed << setprecision(2) << result;

	return 0;
}