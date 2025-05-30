#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Parents[1001];

int Find(int a)
{
	if (Parents[a] == -1) return a;

	return Parents[a] = Find(Parents[a]);
}

void Union(int a, int b)
{
	int aP = Find(a);
	int bP = Find(b);
	if (aP == bP) return;
	if (aP < bP)
		Parents[bP] = aP;
	else
		Parents[aP] = bP;
}

int Output[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr.begin(), arr.end());
	memset(Parents, -1, sizeof(Parents));
	int output = 0;
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		int pos = Find(arr[i].second);
		if (pos != 0)
		{
			output += arr[i].first;
			Union(pos, pos - 1);
		}
	}
	cout << output;


	return 0;
}

/*
5 + 60 + 30 + 50 + 20

*/