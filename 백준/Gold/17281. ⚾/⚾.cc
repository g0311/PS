#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

int n;
vector<vector<int>> Point;
set<vector<int>> Set;
int Visited[9];

int Simulate(const vector<int>& arr)
{
	int score = 0;
	int playerIdx = 0;
	for (int i = 0; i < n; i++)
	{
		int OutCount = 0;
		int Base[3] = { 0, 0, 0 };
		while (OutCount < 3)
		{
			int cur = Point[i][arr[playerIdx]];

			if (cur == 0)
			{
				OutCount++;
			}
			else if (cur == 1)
			{
				score += Base[2];
				Base[2] = Base[1];
				Base[1] = Base[0];
				Base[0] = 1;
			}
			else if (cur == 2)
			{
				score += Base[2];
				score += Base[1];
				Base[2] = Base[0];
				Base[1] = 1;
				Base[0] = 0;
			}
			else if (cur == 3)
			{
				score += Base[2];
				score += Base[1];
				score += Base[0];
				Base[2] = 1;
				Base[1] = 0;
				Base[0] = 0;
			}
			else if (cur == 4)
			{
				score += Base[2];
				score += Base[1];
				score += Base[0];
				score += 1;
				Base[2] = 0;
				Base[1] = 0;
				Base[0] = 0;
			}

			playerIdx = (playerIdx + 1) % 9;
		}
	}

	return score;
}

int DFS(int ct, vector<int>& order)
{
	if (ct == 9)
	{
		return Simulate(order);
	}

	int out = 0;
	if (ct == 3) 
	{
		order.push_back(0);
		Visited[0] = true;
		out = max(out, DFS(ct + 1, order));
		order.pop_back();
		Visited[0] = false;
	}
	else
	{
		for (int i = 1; i < 9; i++)
		{
			if (Visited[i])
				continue;
			Visited[i] = 1;
			order.push_back(i);
			out = max(out, DFS(ct + 1, order));
			order.pop_back();
			Visited[i] = 0;
		}
	}
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	Point.resize(n);
	for (int i = 0; i < n; i++) {
		Point[i].resize(9);
		for (int j = 0; j < 9; j++) {
			cin >> Point[i][j];
		}
	}
	vector<int> vec;
	cout << DFS(0, vec) << endl;

	return 0;
}