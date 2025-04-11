
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
    int DP[1001];
    DP[1] = 2; //l
    DP[2] = 1; //w
    DP[3] = 2; //l

	for (int i = 4; i <= N; i++)
	{
        //상근이 시작, 다음에 지는거 골라야함
        if (max(DP[i - 1], DP[i - 3]) == 2)
        {
            DP[i] = 1;
        }
        else
        {
            DP[i] = 2;
        }
    }

	if (DP[N] == 1)
		cout << "SK";
	else
		cout << "CY";

    return 0;
}