#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T;
	cin >> N >> T;
	vector<pair<int, int>> alc(N);

	int minA = 0, maxA = 100'000'000;
	int minSum = 0, maxSum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> alc[i].first >> alc[i].second;
		minA = max(alc[i].first, minA);
		minSum += alc[i].first;
		maxSum += alc[i].second;
	}
	if (minSum > T || maxSum < T)
	{
		cout << -1;
		return 0;
	}


	while (minA <= maxA)
	{
		int mid = (minA + maxA) / 2;
		
		int out = 0;
		for (int i = 0; i < N; i++)
		{
			out += min(mid, alc[i].second);
		}
		
		if (out < T)
		{
			minA = mid + 1;
		}
		else
		{
			maxA = mid - 1;
		}
	}

	int out = 0;
	for (int i = 0; i < N; i++)
	{
		out += min(minA, alc[i].second);
	}
	if (out >= T)
		cout << minA;
	else
		cout << -1;

	return 0;
}