#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<bool> isPrime(10001, true);
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 2; i <= 10000; i++)
	{
		if (!isPrime[i])
			continue;
		int cur = i * 2;
		int id = 3;
		while (cur <= 10000)
		{
			isPrime[cur] = false;
			cur = i * id++;
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		
		int curNo = n / 2;
		for (int i = curNo; i >= 2; i--)
		{
			if (isPrime[i] && isPrime[n - i])
			{
				cout << i << " " << n - i << endl;
				break;
			}
		}
	}
	
	return 0;
}

/*
9973936905
9973936905
*/