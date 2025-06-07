#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

pair<int,int> DP[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		DP[i].first = 1;
		DP[i].second = -1;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if (DP[i].first < DP[j].first + 1)
				{
					DP[i].first = DP[j].first + 1;
					DP[i].second = j;
				}
			}
		}
	}

	int maxLength = 0;
	int maxId = 0;
	for (int i = 0; i < N; i++)
	{
		if (maxLength < DP[i].first)
		{
			maxLength = DP[i].first;
			maxId = i;
		}
	}
	cout << maxLength << endl;
	vector<int> out;
	while (maxId != -1)
	{
		out.push_back(A[maxId]);
		maxId = DP[maxId].second;
	}
	for (int i = out.size()-1; i >= 0; i--)
	{
		cout << out[i] << " ";
	}


	return 0;
}