
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

    int st = 0; int ed = N - 1;
    int minOutput = abs(arr[st] + arr[ed]);
    int outputL = 0; int outputR = N - 1;
    while (st < ed)
    {
        int sum = arr[st] + arr[ed];
        if (abs(sum) < minOutput)
        {
			minOutput = abs(sum);
			outputL = st;
			outputR = ed;
        }

        if (sum < 0)
        {
            st++;
        }
        else
        {
            ed--;
        }
    }
    cout << arr[outputL] << " " << arr[outputR] << endl;

    return 0;
}