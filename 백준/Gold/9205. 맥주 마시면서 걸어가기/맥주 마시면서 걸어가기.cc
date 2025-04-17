
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int N;
pair<int, int> st;
vector<pair<int, int>> conven;
pair<int, int> ed;

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool Solve(pair<int, int> st)
{
    queue<pair<int, int>> q;
	vector <bool> visited(N + 1, false);
	q.push(st);
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (dist({x, y}, ed) <= 1000)
			return true;
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (!visited[i] && dist({x, y}, conven[i]) <= 1000)
				{
					visited[i] = true;
					q.push(conven[i]);
				}
			}
		}
	}
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
	cin >> TC;
    while (TC--)
    {
		cin >> N;

		cin >> st.first >> st.second;
		conven.resize(N);
        for (int i = 0; i < N; i++)
        {
			cin >> conven[i].first >> conven[i].second;
        }
		cin >> ed.first >> ed.second;

		if(Solve(st))
			cout << "happy" << endl;
        else
			cout << "sad" << endl;
    }

    return 0;
}