#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <set>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int n = (int)A.size();
    int m = (int)B.size();

    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) 
    {
        DP[i][0] = i;
    }
    for (int j = 0; j <= m; j++) 
    {
        DP[0][j] = j;
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = min({
                    DP[i - 1][j] + 1,
                    DP[i][j - 1] + 1,
                    DP[i - 1][j - 1] + 1
                    });
            }
        }
    }

    cout << DP[n][m] << endl;

    return 0;
}
/*
10101010


*/