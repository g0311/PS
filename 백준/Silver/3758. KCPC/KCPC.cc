#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long

bool Comp(tuple<int, int, int, map<int, int>, int> a, tuple<int, int, int, map<int, int>, int> b)
{
	if (get<0>(a) > get<0>(b))
		return true;
	else if (get<0>(a) < get<0>(b))
		return false;
	else
	{
		if (get<1>(a) < get<1>(b))
			return true;
		else if (get<1>(a) > get<1>(b))
			return false;
		else
		{
			if (get<2>(a) < get<2>(b))
				return true;
			else if (get<2>(a) > get<2>(b))
				return false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		
		//점수, 제출횟수, 마지막 제출시간, 각 문제별 점수
		vector<tuple<int, int, int, map<int, int>, int>> teams(n + 1);
		get<0>(teams[0]) = -1;
		for (int i = 0; i <= n; i++)
		{
			get<4>(teams[i]) = i;
		}
		for (int i = 0; i < m; i++)
		{
			int team, pId, score;
			cin >> team >> pId >> score;
			if (get<3>(teams[team]).find(pId) == get<3>(teams[team]).end())
			{
				get<3>(teams[team])[pId] = score;
				get<0>(teams[team]) += score;
			}
			else
			{
				if (get<3>(teams[team])[pId] < score)
				{
					get<0>(teams[team]) += (score - get<3>(teams[team])[pId]);
					get<3>(teams[team])[pId] = score;
				}
			}
			get<2>(teams[team]) = i;
			get<1>(teams[team])++;
		}
		sort(teams.begin(), teams.end(), Comp);
		for (int i = 0; i < n; i++)
		{
			if (get<4>(teams[i]) == t)
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}

	return 0;
}