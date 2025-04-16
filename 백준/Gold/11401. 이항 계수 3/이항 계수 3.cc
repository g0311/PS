
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

ll Pow(ll a, ll b)
{
	ll result = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			result *= a;
			result %= INF;
		}
		a *= a;
		a %= INF;
		b /= 2;
	}
	return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    // A Mod P == A^P Mod P
    // (N! / (K! * (N - K)!)) % INF
	// ((N! % INF) * ((K! * (N - K)!)^-1 % INF)) % INF
	// (N! % INF) * ((K! % INF) * ((N - K)! % INF))^INF-2 % INF

    ll Top = 1;
    for(int i = 1; i <= N; i++)
	{
		Top *= i;
		Top %= INF;
	}

	ll Bottom = 1;
    for (int i = 1; i <= K; i++)
    {
		Bottom *= i;
		Bottom %= INF;
    }
    for (int i = 1; i <= N - K; i++)
    {
		Bottom *= i;
		Bottom %= INF;
    }

    ll output = (Top * Pow(Bottom, INF - 2)) % INF;
    cout << output;

    return 0;
}