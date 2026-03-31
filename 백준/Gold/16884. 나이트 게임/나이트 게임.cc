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

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << "cubelover" << endl;
        }
        else
        {
            cout << "koosaga" << endl;
        }
    }

    return 0;
}
