#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long

int Map[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<ll> nums(N + 1);
	vector <ll> cnt(M, 0);
	nums[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		nums[i] += nums[i - 1];
		nums[i] %= M;
		cnt[nums[i]]++;
	}

	ll output = cnt[0];
	for (int i = 0; i < M; i++)
	{
		ll temp = cnt[i] * (cnt[i] - 1);
		temp /= 2;
		output += temp;
	}

	cout << output;

	return 0;
}

/*
0 1 3 6 7 9
(ai - aj)%M == 0
(ai % M - aj % M) == 0 
ai % M == aj % M
*/