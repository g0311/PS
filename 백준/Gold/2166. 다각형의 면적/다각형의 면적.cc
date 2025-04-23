
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<ll,ll>> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	double output = 0;
	for (int i = 0; i < N - 1; i++)
	{
		output += A[i].first * A[i + 1].second - A[i + 1].first * A[i].second;
	}
	output += A[N-1].first * A[0].second - A[0].first * A[N-1].second;
	cout << fixed;
	cout << setprecision(1);
	cout << abs(output) / 2 << endl;

	return 0;
}