#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
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

    int N, M;
    if (!(cin >> N >> M)) return 0;

    map<int, deque<int>, greater<int>> Arr;

    for (int i = 1; i <= N; ++i)
    {
        int no;
        cin >> no;
        Arr[no].push_back(i);
    }

    bool bIsReversed = false;

    for (int i = 0; i < M; ++i) 
    {
        auto it = Arr.begin();
        int curNo = it->first;
        int curId;

        if (!bIsReversed) 
        {
            curId = it->second.front();
            it->second.pop_front();
        }
        else
        {
            curId = it->second.back();
            it->second.pop_back();
        }

        cout << curId << endl;

        if (it->second.empty()) 
        {
            Arr.erase(it);
        }
        if (curNo % 7 == 0)
        {
            bIsReversed = !bIsReversed;
        }
    }

    return 0;
}