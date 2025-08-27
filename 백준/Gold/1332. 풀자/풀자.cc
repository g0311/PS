#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

int N, V;
vector<int> arr;
int out = INF;
bool visited[51][1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> V;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	queue<tuple<int, int, int, int>> q;
	q.push({ 0, arr[0], arr[0], 1 });
	visited[0][arr[0]][arr[0]] = true;

	while (!q.empty()) 
	{
		auto [id, min_val, max_val, count] = q.front();
		q.pop();

		if (id + 1 < N) 
		{
			int next_id = id + 1;
			int new_min = min(min_val, arr[next_id]);
			int new_max = max(max_val, arr[next_id]);
			int new_count = count + 1;

			if (new_max - new_min >= V) 
			{
				cout << new_count << endl;
				return 0;
			}

			if (!visited[next_id][new_min][new_max]) 
			{
				visited[next_id][new_min][new_max] = true;
				q.push({ next_id, new_min, new_max, new_count });
			}
		}

		if (id + 2 < N) 
		{
			int next_id = id + 2;
			int new_min = min(min_val, arr[next_id]);
			int new_max = max(max_val, arr[next_id]);
			int new_count = count + 1;

			if (new_max - new_min >= V) 
			{
				cout << new_count << endl;
				return 0;
			}

			if (!visited[next_id][new_min][new_max]) 
			{
				visited[next_id][new_min][new_max] = true;
				q.push({ next_id, new_min, new_max, new_count });
			}
		}
	}

	cout << N << endl;

	return 0;
}
