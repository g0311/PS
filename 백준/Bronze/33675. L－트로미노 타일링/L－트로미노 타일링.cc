
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

        cout << (N % 2 ? 0 : (1LL << (N / 2))) << endl;
            // 1LL << N => 2^N (정수 연산)
			// pow(2, N) => 2^N (실수 연산) => 오차발생
    }
    return 0;
}