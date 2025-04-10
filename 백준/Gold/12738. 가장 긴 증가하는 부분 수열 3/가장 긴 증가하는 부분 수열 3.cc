
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define endl '\n'
#define INF 2e9


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> DP;
    for (int i = 0; i < N; i++)
    {
        auto iter = lower_bound(DP.begin(), DP.end(), arr[i]);
        if (iter == DP.end())
            DP.push_back(arr[i]);
        else
            *iter = arr[i];
    }
    cout << DP.size() << endl;

    return 0;
}