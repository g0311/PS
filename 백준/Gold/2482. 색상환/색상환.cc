
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'003

int DP[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    if (n < 2 * k)
    {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i <= n; i++)
    {
		DP[i][0] = 1;
		DP[i][1] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            DP[i][j] = (DP[i - 2][j - 1] + DP[i - 1][j]) % INF;
        }
    }

	int ans = (DP[n - 3][k - 1] + DP[n - 1][k]) % INF;
    cout << ans;
    return 0;
}