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

    int n;
    cin >> n;

    vector<int> Arr(n + 1);
    Arr[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> Arr[i];
        Arr[i] += Arr[i - 1];
    }

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int a, b;
        cin >> a >> b;

        cout << Arr[b] - Arr[a - 1] << endl;
    }

    return 0;
}
