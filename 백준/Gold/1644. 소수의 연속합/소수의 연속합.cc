#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>

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

	vector<bool> arr(N + 1);
	arr[1] = false;
	for (int i = 2; i <= N; i++)
		arr[i] = true;
	for (int i = 2; i <= (int)sqrt(N); i++)
	{
		if (!arr[i])
			continue;
		for (int j = i * i; j <= N; j += i)
		{
			arr[j] = false;
		}
	}
	vector<int> prime(1,0);
	for (int i = 2; i <= N; i++)
	{
		if (arr[i])
			prime.push_back(i);
	}
	for (int i = 1; i < prime.size(); i++)
	{
		prime[i] += prime[i - 1];
	}

	int st = 0; int ed = 0;
	int output = 0;
	while (ed < prime.size())
	{
		int curSum = prime[ed] - prime[st];
		if (curSum > N)
		{
			st++;
		}
		else if (curSum == N)
		{
			output++;
			ed++;
		}
		else
		{
			ed++;
		}
	}
	cout << output;

	return 0;
}

/*
 1 2 3
 1 3 6

*/