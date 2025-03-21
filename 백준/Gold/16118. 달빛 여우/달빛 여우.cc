#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 2'000'000'000

vector<pair<int,int>> edge[4001];
ll wVisit[4001][2];
ll fVisit[4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ 2*c,b });
		edge[b].push_back({ 2*c,a });
	}

	for (int i = 0; i <= N; i++)
	{
		wVisit[i][0] = MAX;
		wVisit[i][1] = MAX;
		fVisit[i] = MAX;
	}

	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> q1;
	q1.push({0, {1, 1}});
	wVisit[1][1] = 0;
	while (!q1.empty())
	{
		ll curW = q1.top().first;
		int curV = q1.top().second.first;
		int is2nd = q1.top().second.second;
		q1.pop();
		if (wVisit[curV][is2nd] < curW) //0 : 뛰왔, 1 : 걸왔
			continue;

		for (int i = 0; i < edge[curV].size(); i++)
		{
			ll nexW;
			if (is2nd == 0) //curV까지 뛰왔
			{
				nexW = edge[curV][i].first * 2 + curW;
			}
			else
			{
				nexW = edge[curV][i].first / 2 + curW;
			}
			int nexV = edge[curV][i].second;
			int nexIs2nd = 1 - is2nd;
			if (nexW < wVisit[nexV][nexIs2nd])
			{
				q1.push({ nexW, {nexV, nexIs2nd} });
				wVisit[nexV][nexIs2nd] = nexW;
			}
		}
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q2;
	q2.push({ 0, 1 });
	fVisit[1] = 0;
	while (!q2.empty())
	{
		ll curW = q2.top().first;
		int curV = q2.top().second;
		q2.pop();

		if (fVisit[curV] < curW)
			continue;

		for (int i = 0; i < edge[curV].size(); i++)
		{
			ll nexW = curW + edge[curV][i].first;
			int nexV = edge[curV][i].second;
			if(nexW < fVisit[nexV])
			{
				fVisit[nexV] = nexW;
				q2.push({ nexW, nexV });
			}
		}
	}

	int output = 0;
	for (int i = 1; i <= N; i++)
	{
		if (fVisit[i] < min(wVisit[i][0], wVisit[i][1]))
			output++;
	}
	cout << output;

	return 0;
}


// 3   2   7    6
//1.5  1   7   7.5