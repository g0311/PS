
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

vector<pair<int, int>> checkPoints;

int dist(int id1, int id2)
{
	return abs(checkPoints[id1].first - checkPoints[id2].first) + abs(checkPoints[id1].second - checkPoints[id2].second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int sum = 0;
	int minOutput = INF;
	vector<int> dists1(N);
	vector<int> dists2(N);

	checkPoints.resize(N);
	cin >> checkPoints[0].first >> checkPoints[0].second;
	cin >> checkPoints[1].first >> checkPoints[1].second;
	dists1[1] = dist(0, 1);
	sum += dists1[1];

	for (int i = 2; i < N; i++)
	{
		cin >> checkPoints[i].first >> checkPoints[i].second;
		dists1[i] = dist(i, i - 1);
		sum += dists1[i];
		dists2[i] = dist(i, i - 2) - dists1[i] - dists1[i - 1];
		minOutput = min(minOutput, dists2[i]);
	}

	cout << sum + minOutput << endl;

	return 0;
}
