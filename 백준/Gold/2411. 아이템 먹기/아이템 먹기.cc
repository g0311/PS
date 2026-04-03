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
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807
#define MOD 1'000'000'007

int N, M, A, B;
int DP[101][101];
int Obstacles[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> A >> B;
	vector<pii> Items(A);
	for (int i = 0; i < A; ++i)
	{
		cin >> Items[i].first >> Items[i].second;
	}
	Items.push_back({ N, M });
	sort(Items.begin(), Items.end());

	for (int i = 0; i < B; ++i)
	{
		int x, y;
		cin >> x >> y;
		Obstacles[x][y] = 1;
	}
	
	DP[1][1] = 1;
	pii st = { 1,1 };
	for (int idx = 0; idx < Items.size(); ++idx)
	{
		pii ed = Items[idx];

		for (int i = st.first; i <= ed.first; ++i)
		{
			for (int j = st.second; j <= ed.second; ++j)
			{
				if (i == st.first && j == st.second) continue;

				if (Obstacles[i][j])
				{
					DP[i][j] = 0;
				}
				else
				{
					DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
				}
			}
		}
		st = ed;
	}

	cout << DP[N][M];

	return 0;
}
