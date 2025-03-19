#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'
#define ll long long

int N;
vector<int> map[123'457];
vector<pair<int, ll>> iss;

ll Solve(int id)
{
	int isSheep = iss[id].first;
	ll sheep = 0, wolf = 0;
	if (isSheep)
		sheep += iss[id].second;
	else
		wolf += iss[id].second;

	for (int i = 0; i < map[id].size(); i++)
	{
		int nextIsl = map[id][i];
		sheep += Solve(nextIsl);
	}
	if (wolf > sheep)
		return 0;
	else
		return sheep - wolf;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	iss.push_back({ 0, 0 });
	iss.push_back({ 0, 0 });
	for (int i = 2; i <= N; i++)
	{
		char a; int b, c;
		cin >> a >> b >> c;
		if(a=='S')
			iss.push_back({ 1,b });
		else
			iss.push_back({ 0,b });

		map[c].push_back(i);
	}
	cout << Solve(1);

	return 0;
}