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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	string pos;
	cin >> pos;
	
	int output = 0;
	for (int i = 0; i < pos.size(); i++)
	{
		if (pos[i] == 'P')
		{
			for (int j = i - K; j <= i + K; j++)
			{
				if (j < 0 || j > pos.size())
					continue;
				if (pos[j] == 'H')
				{
					output++;
					pos[j] = 'X';
					break;
				}
			}
		}
	}

	cout << output;

	return 0;
}
