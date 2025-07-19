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
#define INF 1e9

int Map[101][101];
int Visited[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, L, R;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cin >> Map[i][j];
		}
	}

	bool ShouldIter = true;
	int output = 0;
	while(ShouldIter)
	{
		ShouldIter = false;
		memset(Visited, 0, sizeof(Visited));
		vector<pair<int, vector<pair<int, int>>>> Unions;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Visited[i][j] == 1)
				{
					continue;
				}
				queue<pair<int, int>> q;
				vector<pair<int, int>> Union;
				q.push({ i, j });
				Visited[i][j] = 1;
				int Sum = Map[i][j];
				Union.push_back({ i, j });
				while(!q.empty())
				{
					auto [y, x] = q.front();
					q.pop();
					for (int dx = -1; dx <= 1; dx++)
					{
						for (int dy = -1; dy <= 1; dy++)
						{
							if (abs(dx) + abs(dy) == 1)
							{
								int ny = dy + y;
								int nx = dx + x;
								if (ny >= 0 && ny < N && nx >= 0 && nx < N && Visited[ny][nx] == 0)
								{
									int diff = abs(Map[y][x] - Map[ny][nx]);
									if (diff >= L && diff <= R)
									{
										q.push({ ny, nx });
										Visited[ny][nx] = 1;
										Sum += Map[ny][nx];
										Union.push_back({ ny, nx });
									}
								}
							}
						}
					}
				}
				if (Union.size() != 1)
				{
					Unions.push_back({ Sum, Union });
					ShouldIter = true;
				}
			}
		}

		if (ShouldIter)
		{
			output++;
			for (const auto& unionData : Unions)
			{
				int NewCount = unionData.first / unionData.second.size();
				for (const auto& pos : unionData.second)
				{
					Map[pos.first][pos.second] = NewCount;
				}
			}
		}
		else
		{
			break;
		}
	}
	cout << output << endl;

	return 0;
}