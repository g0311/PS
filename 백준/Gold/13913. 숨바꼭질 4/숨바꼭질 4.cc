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

int Visited[100'001];
int Path[100'001];
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(Visited, -1, sizeof(Visited));
	memset(Path, -1, sizeof(Path));
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	Visited[N] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur - 1 >= 0 && Visited[cur - 1] == -1)
		{
			q.push(cur - 1);
			Path[cur - 1] = cur;
			Visited[cur - 1] = Visited[cur] + 1;
		}

		if (cur + 1 <= 100'000 && Visited[cur + 1] == -1)
		{
			q.push(cur + 1);
			Path[cur + 1] = cur;
			Visited[cur + 1] = Visited[cur] + 1;
		}

		if (cur * 2 <= 100'000 && Visited[cur * 2] == -1)
		{
			q.push(cur * 2);
			Path[cur * 2] = cur;
			Visited[cur * 2] = Visited[cur] + 1;
		}
	}

	cout << Visited[K] << endl;

	vector<int> path;
	int current = K;
	while (current != N) 
	{
		path.push_back(current);
		current = Path[current];
	}
	path.push_back(N);
	reverse(path.begin(), path.end());
	for (int pos : path) 
	{
		cout << pos << " ";
	}
	cout << endl;


    return 0;
}
