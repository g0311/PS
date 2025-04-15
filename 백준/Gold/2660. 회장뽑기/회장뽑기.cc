#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<int> rel[51];
int visited[51];

bool Comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 || b == -1)
			break;

		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	vector<int> scs(N + 1);
	int minPoint = INF;
	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		queue<pair<int,int>> q;
		visited[i] = 1;
		for (int no : rel[i])
		{
			q.push({ no, 1 });
			visited[no] = 1;
		}
		int maxSc = 1;
		while (!q.empty())
		{
			int curP = q.front().first;
			int curSc = q.front().second;
			maxSc = max(maxSc, curSc);
			q.pop();
			for (int no : rel[curP])
			{
				if (visited[no])
					continue;

				q.push({ no, curSc + 1 });
				visited[no] = 1;
			}
		}
		scs[i] = maxSc;
		minPoint = min(minPoint, maxSc);
	}

	vector<int> output;
	for (int i = 1; i <= N; i++)
	{
		if (scs[i] == minPoint)
			output.push_back(i);
	}

	cout << minPoint << " " << output.size() << endl;
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << " ";

	return 0;
}
