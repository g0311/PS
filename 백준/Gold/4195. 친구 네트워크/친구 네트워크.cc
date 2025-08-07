#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

class UnionFind {
private:
	vector<int> parent, size;

public:
	UnionFind(int n) 
	{
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int x) 
	{
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}

	void unite(int x, int y) 
	{
		int rx = find(x);
		int ry = find(y);
		if (rx == ry) return;

		if (size[rx] < size[ry]) swap(rx, ry);

		parent[ry] = rx;
		size[rx] += size[ry];
	}

	int getSize(int x) 
	{
		return size[find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		UnionFind uf(n * 2);
		map<string, int> Map;
		int ct = 0;
		for (int i = 0; i < n; i++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			if (Map.find(str1) == Map.end())
			{
				Map.insert({ str1, ct++ });
			}
			if (Map.find(str2) == Map.end())
			{
				Map.insert({ str2, ct++ });
			}
			uf.unite(Map[str1], Map[str2]);
			cout << uf.getSize(uf.find(Map[str1])) << endl;
		}
	}

	return 0;
}