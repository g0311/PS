#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int arr[2001][2001];

bool comp(tuple<int, int, int> a, tuple<int, int, int> b)
{
	int a1 = get<0>(a), a2 = get<1>(a), a3 = get<2>(a);
	int b1 = get<0>(b), b2 = get<1>(b), b3 = get<2>(b);
	if (a2 < b2)
	{
		return true;
	}
	else if (a2 == b2)
	{
		return a1 <= b1;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, C, M;
	cin >> N >> C >> M;
	vector<tuple<int, int, int>> arr(M);
	for (int i = 0; i < M; i++)
	{
		cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
	}
	sort(arr.begin(), arr.end(), comp);
	
	int output = 0;
	vector<int> cities(N + 1, C);
	for (int i = 0; i < M; i++)
	{
		int st = get<0>(arr[i]);
		int ed = get<1>(arr[i]);
		int w = get<2>(arr[i]);
		int maxCt = INF;
		for (int j = st; j < ed; j++)
		{
			maxCt = min(maxCt, cities[j]);
		}

		maxCt = min(maxCt, w);
		for (int j = st; j < ed; j++)
		{
			cities[j] -= maxCt;
		}
		output += maxCt;
	}
	cout << output;

	return 0;
}
