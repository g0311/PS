#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[51][51];
bool Selected[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char X;
			cin >> X;
			if (X >= 'a' && X <= 'z')
			{
				Map[i][j] = X - 'a' + 1;
				total += Map[i][j];
			}
			else if (X >= 'A' && X <= 'Z')
			{
				Map[i][j] = X - 'A' + 27;
				total += Map[i][j];
			}
			else
			{
				Map[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Map[i][j] = min(Map[i][j], Map[j][i]);
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	Selected[0] = true;
	for (int i = 0; i < N; i++)
	{
		if (Map[0][i] != INF)
			pq.push({ Map[0][i], i });
	}
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (Selected[x])
			continue;
		Selected[x] = true;
		total -= cost;
		for (int y = 0; y < N; y++)
		{
			if (Map[x][y] != INF && !Selected[y])
			{
				pq.push({Map[x][y], y});
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!Selected[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}

	cout << total << endl;

	return 0;
}