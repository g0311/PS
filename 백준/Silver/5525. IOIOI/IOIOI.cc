
#include <iostream>
#include <list>
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
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	string str;
	cin >> str;

	int output = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'I')
		{
			int k = 0;
			while (str[i + 1] == 'O' && str[i + 2] == 'I')
			{
				k++;
				if (k == N)
				{
					k--;
					output++;
				}
				i += 2;
			}
		}
		else
		{
			continue;
		}
	}
	cout << output;


	return 0;
}