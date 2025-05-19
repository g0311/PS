#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int N, M;
vector<int> A;

int output = 0;
void Solve(int id, int sum, int cnt) {
	if (sum == M && cnt > 0) {
		output++;
	}
	for (int i = id; i < N; i++) {
		Solve(i + 1, sum + A[i], cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	Solve(0, 0, 0);
	cout << output << endl;

	return 0;
}
