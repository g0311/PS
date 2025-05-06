#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
//#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	int SQ = max(N, M);

	int i = N * M % 2 == 0 ? 1 : 2;
	for (i; i <= SQ * 2; i += 2)
	{
		int X = 1, Y = i;
		while (Y >= 1)
		{
			if (Y > N || Y <= 0 || X > M || X <= 0)
			{
				X++; Y--;
				continue;
			}

			cout << "? " << Y << " " << X << endl;

			int out;
			cin >> out;
			if (out == 1)
			{
				return 0;
			}
			X++; Y--;
		}
	}


	return 0;
}
/*
123456 5
512346
*/