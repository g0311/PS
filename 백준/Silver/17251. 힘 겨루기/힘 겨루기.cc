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

    vector<int> Arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
    }

    vector<int> lMax(N);
    vector<int> rMax(N);

    lMax[0] = Arr[0];
    for (int i = 1; i < N; i++) 
    {
        lMax[i] = max(lMax[i - 1], Arr[i]);
    }

    rMax[N - 1] = Arr[N - 1];
    for (int i = N - 2; i >= 0; i--) 
    {
        rMax[i] = max(rMax[i + 1], Arr[i]);
    }

    int redCount = 0;
    int blueCount = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        int lVal = lMax[i];
        int rVal = rMax[i + 1];
        if (lVal > rVal)
        {
            ++redCount;
        }
        else if (lVal < rVal)
        {
            ++blueCount;
        }
    }
    
    if (redCount > blueCount)
    {
        cout << "R" << endl;
    }
    else if (redCount < blueCount)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "X" << endl;
    }

    return 0;
}
