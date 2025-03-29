#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int aP = 0, bP = 0;
		
		int output = 0;
		for (int i = 0; i < N; i++)
		{
			auto iter = lower_bound(B.begin(), B.end(), A[i]);
			int id = iter - B.begin() + 1;
			output += id;
			if (iter == B.end() || *iter >= A[i])
				output--;
		}

		cout << output << endl;
	}

	return 0;
}

/*
2 3 4 5 6
1 2 3 4 5

*/