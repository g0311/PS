#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ll long long

ll map[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int p = 0, ct = 10'000'001;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			cin >> a;
			map[i][j] = map[i][j - 1] + a;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[j][i] >= K)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}

	return 0;
}

/*
1 3
2 6
3 4
4 6
5 3
6 7
7 3
8 6
9 4
10 6

*/