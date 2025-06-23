#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> Pack(M);
	vector<int> Single(M);
	for (int i = 0; i < M; i++)
	{
		cin >> Pack[i] >> Single[i];
	}
	sort(Pack.begin(), Pack.end());
	sort(Single.begin(), Single.end());

	int pack = Pack[0];
	int single = Single[0];
	if (pack > single * 6)
	{
		pack = single * 6;
	}

	int ans = 0;
	int packCt = N / 6; N %= 6;
	int singleCt = N;

	ans += pack * packCt;
	if (pack < single * singleCt)
	{
		ans += pack;
	}
	else
	{
		ans += single * singleCt;
	}

	cout << ans;

	return 0;
}