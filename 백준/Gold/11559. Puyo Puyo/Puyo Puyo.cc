#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9

char Map[12][6];
bool Visited[12][6];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> Map[i][j];
		}
	}

	bool IsEnd = false;
	int ans = 0;
	while (!IsEnd)
	{
		IsEnd = true;
		memset(Visited, false, sizeof(Visited));
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Map[i][j] != '.' && !Visited[i][j])
				{
					char TargetCh = Map[i][j];
					queue<pair<int, int>> q;
					q.push({ i,j });
					Visited[i][j] = true;
					int ct = 1;
					vector<pair<int, int>> V;
					V.push_back({ i,j });
					while (!q.empty())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int dx = -1; dx <= 1; dx++)
						{
							for (int dy = -1; dy <= 1; dy++)
							{
								if (abs(dx) + abs(dy) == 1)
								{
									int ny = y + dy;
									int nx = x + dx;
									if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && !Visited[ny][nx] && Map[ny][nx] == TargetCh)
									{
										q.push({ ny,nx });
										Visited[ny][nx] = true;
										ct++;
										V.push_back({ ny,nx });
									}
								}
							}
						}
					}
					if (ct >= 4)
					{
						if (IsEnd) 
						{
							IsEnd = false; 
							ans++;
						}
						for (auto& p : V)
						{
							Map[p.first][p.second] = '0';
						}
					}
				}
			}
		}
		if (!IsEnd)
		{
			for (int j = 0; j < 6; j++)
			{
				int idx = 11;
				for (int i = 11; i >= 0; i--)
				{
					if (Map[i][j] != '0')
					{
						Map[idx--][j] = Map[i][j];
					}
				}
				while (idx >= 0)
				{
					Map[idx--][j] = '.';
				}
			}
		}
	}

	cout << ans;

	return 0;
}