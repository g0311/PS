#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int Map[201][201];
int parents[201];

int Find(int x)
{
	if (parents[x] == x) return x;

	return parents[x] = Find(parents[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
	{
		parents[b] = a;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}

	bool isPossible = true;
	vector<int> travelPlan(M);
	for (int i = 0; i < M; i++)
	{
		cin >> travelPlan[i];
	}
	for (int i = 1; i < M; i++)
	{
		if (Find(travelPlan[i]) != Find(travelPlan[i - 1]))
		{
			isPossible = false;
			break;
		}
	}
	if (isPossible)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}