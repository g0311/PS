
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;

        if (N % 2 == 0)
        {
            N /= 2;
            cout << (1LL << N) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}