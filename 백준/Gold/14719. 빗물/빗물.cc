
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    for (int i = 1; i <= W; i++)
    {
        cin >> Map[i];
    }

    int output = 0;
    for (int i = 2; i < W; i++)
    {
        int lef = 0;
        int rig = 0;
        for (int j = 1; j < i; j++)
        {
			lef = max(lef, Map[j]);
        }
        for (int j = i + 1; j <= W; j++)
        {
			rig = max(rig, Map[j]);
        }

        if((min(lef, rig) - Map[i]) > 0)
    		output += (min(lef, rig) - Map[i]);
    }
    cout << output;

    return 0;
}