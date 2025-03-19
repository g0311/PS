#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'

int n;
vector<int> sts;
int st;
int Visited[100'001];

void Solve(int id)
{
	int ne1 = id - sts[id];
	int ne2 = id + sts[id];
	if (ne1 > 0 && Visited[ne1] == 0)
	{
		Visited[ne1] = 1;
		Solve(ne1);
	}
	if (ne2 <= n && Visited[ne2] == 0)
	{
		Visited[ne2] = 1;
		Solve(ne2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	sts.push_back(-1);
	for (int i = 1; i <= n; i++)
	{
		int st;
		cin >> st;
		sts.push_back(st);
	}
	cin >> st;
	Visited[st] = 1;
	Solve(st);

	int output = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Visited[i] != 0)
			output++;
	}
	cout << output;

	return 0;
}