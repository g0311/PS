#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int N;
int Arr[2001];
int Map[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	priority_queue<pii> pq;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
		pq.push({ Arr[i], i });
	}

	while (true)
	{
		if (pq.empty())
			break;

		int curId = pq.top().second;
		int curCt = pq.top().first;
		pq.pop();

		priority_queue<pii> pqTemp;
		while (!pq.empty())
		{
			int tCurId = pq.top().second;
			int tCurCt = pq.top().first;	
			pq.pop();
			if (curCt > 0)
			{
				--curCt; --tCurCt;
				if (curCt < 0 || tCurCt < 0)
				{
					cout << -1;
					return 0;
				}
				++Map[curId][tCurId];
				++Map[tCurId][curId];
			}
			pqTemp.push({ tCurCt, tCurId });
		}

		pq = move(pqTemp);
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
  2 2 2 3
2 0 0 0 1 
2 0 0 1 1
2 0 1 0 1
3 1 1 1 0
*/