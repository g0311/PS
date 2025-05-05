
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int DP[1001][1001];
int Path[1001][1001][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1 = " ";
	string str2 = " ";
	string temp1, temp2;
	cin >> temp1 >> temp2;
	str1 += temp1;
	str2 += temp2;

	for (int i = 1; i < str1.size(); i++)
	{
		for (int j = 1; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
				Path[i][j][0] = i - 1;
				Path[i][j][1] = j - 1;
			}
			else
			{
				if (DP[i - 1][j] > DP[i][j - 1])
				{
					DP[i][j] = DP[i - 1][j];
					Path[i][j][0] = i - 1;
					Path[i][j][1] = j;
				}
				else
				{
					DP[i][j] = DP[i][j - 1];
					Path[i][j][0] = i;
					Path[i][j][1] = j - 1;
				}
			}
		}
	}
	cout << DP[str1.size() - 1][str2.size() - 1] << endl;
	stack<char> stk;
	int x = str1.size() - 1;
	int y = str2.size() - 1;
	while (x != 0 && y != 0)
	{
		if (Path[x][y][0] == x - 1 && Path[x][y][1] == y - 1)
		{
			stk.push(str1[x]);
			x--;
			y--;
		}
		else
		{
			if (Path[x][y][0] == x - 1)
				x--;
			else
				y--;
		}
	}
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}