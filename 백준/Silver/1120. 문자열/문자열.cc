#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

string a, b;
int func(int id)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i + id])
			cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	int minCnt = INF;
	for (int i = 0; i <= b.size() - a.size(); i++)
	{
		minCnt = min(minCnt, func(i));
	}
	cout << minCnt;

	return 0;
}
/*
aababbc 7
 adaabc 6

*/