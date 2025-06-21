#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

char Map[5][5];
pair<int, int> selected[7];
int Ans = 0;
void Solve(int Id, int ct)
{
	if (ct == 7)
	{
		int sCnt = 0;
		for (int i = 0; i < 7; i++)
		{
			if (Map[selected[i].first][selected[i].second] == 'S')
			{
				sCnt++;
			}
		}
		if (sCnt < 4) 
		{
			return;
		}
		else
		{
			queue<pair<int, int>> q;
			bool visited[5][5] = { false };
			q.push({ selected[0].first, selected[0].second });
			visited[selected[0].first][selected[0].second] = true;
			while (!q.empty())
			{
				int i = q.front().first;
				int j = q.front().second;
				q.pop();
				for (int di = -1; di <= 1; di++)
				{
					for (int dj = -1; dj <= 1; dj++)
					{
						if (abs(di) + abs(dj) == 1)
						{
							int ni = i + di;
							int nj = j + dj;
							if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && !visited[ni][nj])
							{
								for (int k = 0; k < 7; k++)
								{
									if (selected[k].first == ni && selected[k].second == nj)
									{
										q.push({ ni, nj });
										visited[ni][nj] = true;
										break;
									}
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < 7; i++)
			{
				if (!visited[selected[i].first][selected[i].second])
				{
					return;
				}
			}
			Ans++;
		}
	}
	else
	{
		for (int i = Id; i < 25; i++)
		{
			int r = i / 5;
			int c = i % 5;
			selected[ct] = { r, c };
			Solve(i + 1, ct + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> Map[i][j];
		}
	}

	Solve(0, 0);
	cout << Ans << endl;

	return 0;
}