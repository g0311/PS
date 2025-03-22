#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'
#define ll long long
#define MAX 1'000'000'007

int FCT(int N, int R)
{
	ll output = 1;
	for (int i = N; i > N - R; i--)
	{
		output *= i;
		output %= MAX;
	}
	return output;
}

ll _POW(ll N, ll R)
{
	if (R == 1)
		return N % MAX;

	if (R % 2 == 0)
	{
		ll half = _POW(N, R / 2);
		return (half * half) % MAX;
	}
	else
	{
		ll half = _POW(N, R / 2);
		return (((half * half) % MAX) * N) % MAX;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R;
	cin >> N >> R;

	ll S = FCT(N, R);
	ll B = FCT(R, R);
	B = _POW(B, MAX - 2);

	int output = ((S * B) % MAX);
	cout << output;

	return 0;
}


/*
N! / (N-K)! * K!

B	500'000'004	int
895385839
155117520
*/