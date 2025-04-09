#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int builds[1001];
//다음 엣지 저장
vector<int> rels[1001];
int ct[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int N, K;
		cin >> N >> K;
		
		for (int i = 1; i <= N; i++)
			cin >> builds[i];
		for (int i = 1; i <= K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			rels[X].push_back(Y);
			ct[Y]++;
		}
		
		int W;
		cin >> W;

		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
		for (int i = 1; i <= N; i++)
		{
			if (ct[i] == 0)
			{
				q.push({ builds[i], i});
				ct[i]--;
			}
		}
		
		while (!q.empty())
		{
			int count = q.top().first;
			int curB = q.top().second;
			if (curB == W)
			{
				cout << count << endl;
				break;
			}
			q.pop();
		
			for (int i = 0; i < rels[curB].size(); i++)
			{
				ct[rels[curB][i]]--;
			}
			for (int i = 1; i <= N; i++)
			{
				if (ct[i] == 0)
				{
					q.push({ count + builds[i], i});
					ct[i]--;
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			rels[i].clear();
			ct[i] = 0;
		}
	}


	return 0;
}