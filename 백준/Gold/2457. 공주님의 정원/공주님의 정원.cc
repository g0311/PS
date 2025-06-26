#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int Calc365(int month, int day)
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDays = day;
	for (int i = 0; i < month - 1; i++)
	{
		totalDays += daysInMonth[i];
	}
	return totalDays;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int st = Calc365(3, 1);
	int ed = Calc365(11, 30);

	int N;
	cin >> N;
	vector<pair<int,int>> Flowers;
	for (int i = 0; i < N; i++)
	{
		int m1 ,m2, d1, d2;
		cin >> m1 >> d1 >> m2 >> d2;
		int start = Calc365(m1, d1);
		int end = Calc365(m2, d2) - 1;
		if (st > end || ed < start) continue;
		Flowers.push_back({ start, end });
	}
	sort(Flowers.begin(), Flowers.end());

	int cnt = 0;
	int cur = st;
	for (int i = 0; i < Flowers.size(); i++)
	{
		if (cur > ed) break;
		if (Flowers[i].first > cur) break;
		int maxEnd = Flowers[i].second;
		while (i + 1 < Flowers.size() && Flowers[i + 1].first <= cur)
		{
			maxEnd = max(maxEnd, Flowers[i + 1].second);
			i++;
		}
		cur = maxEnd + 1;
		cnt++;
	}

	if (cur <= ed) cnt = 0;
	cout << cnt << endl;

	return 0;
}