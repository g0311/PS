#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> map;
	for (int i = 0; i < M; i++)
	{
		int c, x, y;
		cin >> c >> x >> y;
		map.push_back({ x,{y,c} });
	}
	sort(map.begin(), map.end());

	int curY = 0;
	int curX = 0;
	for (int i = 0; i < M; i++)
	{
		int c, x, y;
		c = map[i].second.second;
		x = map[i].first;
		y = map[i].second.first;
		if (c == 0)
		{
			if (curY <= y)
			{
				curX = x;
				curY = y + 1;
			}
			else
			{
				curY = curY - (x - curX);
				if (curY == y)
				{
					curY++;
				}
				curX = x;
			}
		}
		else
		{
			curY = curY - (x - curX);
			if (curY >= y)
			{
				cout << "adios";
				return 0;
			}
			curX = x;
		}
	}
	if (curY > 0 && curY - (N-curX) > 0)
	{
		cout << "adios";
		return 0;
	}

	cout << "stay";

	return 0;
}
