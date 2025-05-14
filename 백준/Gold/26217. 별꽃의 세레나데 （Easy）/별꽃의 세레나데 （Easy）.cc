#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

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

	double output = N;
	double x = 0;
	for (int i = 1; i <= N; i++)
	{
		x += ((double)1 / i);
	}
	output *= x;
	cout << output;

	return 0;
}
