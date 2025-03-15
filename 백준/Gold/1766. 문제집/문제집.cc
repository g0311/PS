#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<pair<int, set<int>>> pInfo(N + 1, {0, set<int>()});
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		pInfo[a].second.insert(b);
		pInfo[b].first++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= N; i++)
	{
		if (pInfo[i].first == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int curV = q.top(); q.pop();
		cout << curV << " ";
		for (int iter : pInfo[curV].second)
		{
			pInfo[iter].first--;
			if (pInfo[iter].first == 0)
			{
				q.push(iter);
			}
		}
	}

	return 0;
}

/*
위상 정렬 + 정렬?
*/