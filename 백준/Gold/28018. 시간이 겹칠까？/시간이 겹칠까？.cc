
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(1'000'002, 0);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] += 1;
        arr[b + 1] -= 1;
    }
    for (int i = 1; i < 1'000'002; i++)
    {
        arr[i] += arr[i - 1];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << arr[q] << endl;
    }

    return 0;
}