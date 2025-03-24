#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int P = 0, B = 0;
	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		P += p;
	}
	for (int i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		B += b;
	}

	cout << B << " " << P;

	return 0;
}