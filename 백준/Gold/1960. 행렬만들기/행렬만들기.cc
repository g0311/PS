#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9

int n;
int row[500];
int col[500];
int Out[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	int rSum = 0, cSum = 0;
	priority_queue<pii>rPq;
	for (int i = 0; i < n; ++i)
	{
		cin >> row[i];
		rSum += row[i];
		rPq.push({ row[i], i});
	}
	priority_queue<pii>cPq;
	for (int i = 0; i < n; ++i)
	{
		cin >> col[i];
		cSum += col[i];
		cPq.push({ col[i], i });
	}

	if (rSum == cSum)
	{
		while (!rPq.empty())
		{
			auto t = rPq.top(); rPq.pop();
			int curR = t.second;
			if (row[curR] == 0)
			{
				continue;
			}

			priority_queue<pii>temp;
			while (!cPq.empty())
			{
				auto t = cPq.top(); cPq.pop();
				int curC = t.second;

				if (col[curC] > 0)
				{
					col[curC]--;
					row[curR]--;
					Out[curR][curC] = 1;
				}
				temp.push({col[curC], curC});
				if (row[curR] == 0)
				{
					while (!cPq.empty())
					{
						temp.push(cPq.top());
						cPq.pop();
					}
					break;
				}
			}
			if (row[curR] != 0)
			{
				cout << -1 << endl;
				return 0;
			}
			cPq = std::move(temp);
		}

		cout << 1 << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << Out[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}