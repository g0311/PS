#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

string Map[25];
bool Visited[25][25];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}

	queue<pair<int, int>>q;
	vector<int> output;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!Visited[i][j] && Map[i][j] == '1')
			{
				q.push({ i, j });
				Visited[i][j] = true;
				int cnt = 0;
				while (!q.empty())
				{
					int I = q.front().first;
					int J = q.front().second;
					q.pop();
					cnt++;
					for (int di = -1; di <= 1; di++)
					{
						for (int dj = -1; dj <= 1; dj++)
						{
							if (abs(di) + abs(dj) != 1) continue;
							int ni = I + di;
							int nj = J + dj;
							if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
							if (Visited[ni][nj] || Map[ni][nj] == '0') continue;
							q.push({ ni, nj });
							Visited[ni][nj] = true;
						}
					}
				}
				output.push_back(cnt);
			}
		}
	}
	sort(output.begin(), output.end());
	cout << output.size() << endl;
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}