#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(7);
	for (int i = 1; i <= 6; i++)
		cin >> A[i];

	if (N == 1)
	{
		int out1 = 0;
		int maxV = -1;
		for (int i = 1; i <= 6; i++)
		{
			out1 += A[i];
			maxV = max(maxV, A[i]);
		}
		out1 -= maxV;
		cout << out1 << endl;
		return 0;
	}

	int out1 = INF;
	for (int i = 1; i <= 6; i++)
	{
		out1 = min(out1, A[i]);
	}
	ll ans = 1LL * (N - 2) * (N - 2) * out1 * 5;
	ans += 1LL * (N - 2) * out1 * 4;

	vector<pair<int, int>> neighbor_pairs;
	for (int i = 1; i <= 6; ++i) {
		for (int j = i + 1; j <= 6; ++j) {
			if (!((i == 1 && j == 6) || (i == 2 && j == 5) || (i == 3 && j == 4)))
			{
				neighbor_pairs.push_back({ i, j });
			}
		}
	}
	int out2 = INF;
	for (const auto& pair : neighbor_pairs) {
		int face1 = pair.first;
		int face2 = pair.second;
		int sum = A[face1] + A[face2];
		out2 = min(out2, sum);
	}
	ans += 1LL * (N - 2) * 4 * out2;
	ans += 1LL * (N - 1) * 4 * out2;


	vector<vector<int>> vertex_combinations = {
	{1, 4, 5}, 
	{1, 4, 2}, 
	{1, 3, 5}, 
	{1, 3, 2}, 
	{6, 4, 2},
	{6, 4, 5},
	{6, 3, 5},
	{6, 3, 2}  
	};
	int out3 = INF;
	for (const auto& combo : vertex_combinations) {
		// char 대신 int를 사용하도록 수정
		int face1 = combo[0];
		int face2 = combo[1];
		int face3 = combo[2];
		int sum = A[face1] + A[face2] + A[face3];
		out3 = min(out3, sum);
	}
	ans += 1LL * (4) * out3;

	cout << ans;

	return 0;
}

/*
   4   4 
 5 1 2 6 5
   3   3
*/