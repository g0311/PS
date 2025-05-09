#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);
	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	vector<int>ASum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = A[i] + B[j];
			ASum.push_back(temp);
		}
	}
	sort(ASum.begin(), ASum.end());

	vector<int>BSum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = C[i] + D[j];
			BSum.push_back(temp);
		}
	}
	sort(BSum.begin(), BSum.end());
	
	ll output = 0;
	for (int i = 0; i < ASum.size(); i++)
	{
		output += upper_bound(BSum.begin(), BSum.end(), -ASum[i])
			- lower_bound(BSum.begin(), BSum.end(), -ASum[i]);
	}
	cout << output;



	return 0;
}
