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

vector<int> grp[11];
vector<int> arr;
vector<int> map[2];
int N;
int output = INF;

bool IsConected(int id)
{
	if (map[id].empty()) 
		return false;

	set<int> groupSet(map[id].begin(), map[id].end());
	vector<bool> visited(11, false);

	vector<int> queue;
	queue.push_back(map[id][0]);
	visited[map[id][0]] = true;

	int visitedCount = 1;
	int front = 0;

	while (front < queue.size())
	{
		int current = queue[front++];
		for (int neighbor : grp[current])
		{
			if (groupSet.count(neighbor) && !visited[neighbor])
			{
				visited[neighbor] = true;
				queue.push_back(neighbor);
				visitedCount++;
			}
		}
	}

	return visitedCount == map[id].size();
}

void DFS(int ct)
{
	if (ct == N + 1)
	{
		if (map[0].size() == 0 || map[1].size() == 0)
		{
			return;
		}
		else
		{
			if (IsConected(0) && IsConected(1))
			{
				int sum1 = 0, sum2 = 0;
				for (int i = 0; i < map[0].size(); i++)
				{
					sum1 += arr[map[0][i]];
				}
				for (int i = 0; i < map[1].size(); i++)
				{
					sum2 += arr[map[1][i]];
				}
				int diff = abs(sum1 - sum2);
				output = min(output, diff);
			}
		}
		return;
	}
	
	map[0].push_back(ct);
	DFS(ct + 1);
	map[0].pop_back();

	map[1].push_back(ct);
	DFS(ct + 1);
	map[1].pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) 
	{
		int ct;
		cin >> ct;
		for (int j = 0; j < ct; j++) 
		{
			int x;
			cin >> x;
			grp[i].push_back(x);
		}
	}
	DFS(1);
	
	if (output == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << output << endl;
	}

	return 0;
}