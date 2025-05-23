#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Map[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		Map[x] = 1;
	}

	int output = 0;
	for (int i = 0; i <= 1000; i++)
	{
		if (Map[i] == 1)
		{
			output++;
			for (int j = i; j < i + L; j++)
			{
				if (j > 1000)
					break;
				Map[j] = 0;
			}
			i += L - 1;
		}
	}
	cout << output << endl;

	return 0;
}
