
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

    int N, K;
    cin >> N >> K;
	vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
		arr[i] += arr[i - 1];
    }

    int output = -100'000'000;
    for (int i = K; i <= N; i++)
    {
		output = max(output, arr[i] - arr[i - K]);
    }

    cout << output;

    return 0;
}