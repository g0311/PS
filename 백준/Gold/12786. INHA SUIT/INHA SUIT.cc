#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long

int N, T;
vector<vector<int>>trees;
int DP[100][21]; //T의 최소사용수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		vector<int> tree(M);
		for (int i = 0; i < M; i++)
		{
			cin >> tree[i];
		}
		trees.push_back(tree);
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j <= 20; j++)
			DP[i][j] = 100'000'000;

	queue<pair<int, int>> q;
	q.push({ 0, 1 });

	for(int curX = 0; curX < N; curX++)
	{
		while (!q.empty())
		{
			int curT = q.front().first;
			int curY = q.front().second;
			q.pop();
			for (int hole : trees[curX])
			{
				if (curY == hole || curY + 1 == hole || curY - 1 == hole || curY * 2 == hole)
				{
					DP[curX][hole] = min(DP[curX][hole], curT);
				}
				else if (curY >= 10 && hole == 20)
				{
					DP[curX][hole] = min(DP[curX][hole], curT);
				}
				else
				{
					DP[curX][hole] = min(DP[curX][hole], curT + 1);
				}
			}
		}
		for (int hole : trees[curX])
		{
			q.push({ DP[curX][hole], hole });
		}
	}
	int output = 100'000'000;
	for (int hole : trees[N - 1])
	{
		output = min(output, DP[N - 1][hole]);
	}
	if (output > T)
		cout << -1;
	else
		cout << output;


	return 0;
}