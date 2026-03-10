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

    int N;
    cin >> N;
    set<pii> Set;
    vector<int> maxR(1'000'001, -1);
    vector<int> minL (1'000'001, INF);
    for (int i = 0; i < N; ++i)
    {
        int st, ed;
        cin >> st >> ed;
        Set.insert(make_pair(st, ed));
        
        maxR[st] = max(maxR[st], ed);
        minL[ed] = min(minL[ed], st);
    }

    int Q;
    cin >> Q;
    for (int Req = 0; Req < Q; ++Req)
    {
        int st, ed;
        cin >> st >> ed;

        if (st > ed)
            swap(st, ed);

        if (Set.find(make_pair(st, ed)) != Set.end())
        {
            cout << 1 << endl;
            continue;
        }

        if (maxR[st] >= ed && minL[ed] <= st)
        {
            cout << 2 << endl;
            continue;
        }

        cout << -1 << endl;
    }


    return 0;
}
/*
l r

L r
l R


*/
