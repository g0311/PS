#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 0, T = 0;
	for (int i = 0; i < 4; i++)
	{
		int sc;
		cin >> sc;
		S += sc;
	}
	for (int i = 0; i < 4; i++)
	{
		int sc;
		cin >> sc;
		T += sc;
	}

	if (S < T)
		cout << T;
	else
		cout << S;

	return 0;
}
