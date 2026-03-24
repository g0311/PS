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

    int TC;
    cin >> TC;
    while (TC--)
    {
        int W, N;
        cin >> W >> N;
        
        int out = 0;
        int curWeight = 0;
        int befPos = 0;

        for (int i = 0; i < N; ++i)
        {
            int x, w;
            cin >> x >> w;

            out += (x - befPos);
            befPos = x;

            if (curWeight + w > W) 
            {
                out += 2 * x;
                curWeight = w;
            }
            else
            {
                curWeight += w;
            }

            if (curWeight == W) 
            {
                out += x;
                curWeight = 0;
                befPos = 0; 
            }
        }

        if (curWeight > 0) 
        {
            out += befPos;
        }

        cout << out << endl;
    }

    return 0;
}
