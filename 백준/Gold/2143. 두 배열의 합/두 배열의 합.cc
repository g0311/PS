#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int T, k;
vector<pair<int, int>> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	int n;
	cin >> n;
	vector<int>A(n + 1);
	A[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
	map<int, int>subA;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int temp = A[j] - A[i - 1];
			if (subA.find(temp) == subA.end())
				subA[temp] = 1;
			else
				subA[temp]++;
		}
	}

	int m;
	cin >> m;
	vector<int>B(m + 1);
	B[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> B[i];
		B[i] += B[i - 1];
	}
	map<int, int>subB;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			int temp = B[j] - B[i - 1];
			if (subB.find(temp) == subB.end())
				subB[temp] = 1;
			else
				subB[temp]++;
		}
	}

	ll output = 0;
	for(auto& p : subA)
	{
		int temp = T - (p.first);
		if (subB.find(temp) != subB.end())
		{
			output += ((ll)subB[temp] * p.second);
		}
	}
	cout << output;

	return 0;
}