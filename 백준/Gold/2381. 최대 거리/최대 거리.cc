#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
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

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		A[i] = a + b;
		B[i] = a - b;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	cout << max(A[N - 1] - A[0], B[N - 1] - B[0]) << endl;

	return 0;
}
