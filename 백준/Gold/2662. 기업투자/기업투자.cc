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
#define LLMAX 9'223'372'036'854'775'807

int N, M;
int Map[301][21];

int Cur$;
int MaxValues[301][21];

int DFS(int id)
{
	if (id == M + 1)
	{
		return 0;
	}

	int MaxProfit = 0;
	for (int i = 0; i <= Cur$; ++i)
	{
		Cur$ -= i;

		if (MaxValues[Cur$][id + 1] == -1)
		{
			MaxValues[Cur$][id + 1] = DFS(id + 1);
		}
		MaxProfit =  max(MaxProfit,Map[i][id] + MaxValues[Cur$][id + 1]);

		Cur$ += i; 
	}

	return MaxProfit;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(MaxValues, -1, sizeof(MaxValues));
	cin >> N >> M;
	Cur$ = N;
	int t;
	for (int i = 1; i <= N; ++i)
	{
		cin >> t;
		for (int j = 1; j <= M; ++j)
		{
			cin >> Map[i][j];
		}
	}

	int Remain = N;
	int curMax = DFS(1);

	cout << curMax << endl;
	for (int id = 1; id <= M; ++id)
	{
		for (int i = 0; i <= Remain; ++i)
		{
			int next = (id == M) ? 0 : MaxValues[Remain - i][id + 1];

			if (Map[i][id] + next == curMax)
			{
				cout << i << " ";
				Remain -= i;
				curMax = next;
				break;
			}
		}
	}
	return 0;
}