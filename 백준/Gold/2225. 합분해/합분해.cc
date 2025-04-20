
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int DP[201][201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= 200; i++)
    {
        DP[1][i] = 1;
        DP[i][0] = 1;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % INF;
        }
    }

	cout << DP[K][N] << endl;

    return 0;
}
/*
  0 1 2 3 4 5 6
1 1 1 1 1 1 1 1
2 1 2 3 4 5 6 7
3 1 3 6 10
4 1 4
5 1 5
6 1 6

1111 112 211 22
*/