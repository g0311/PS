#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

string Map[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}

	int output = 0;
	for (int i = 0; i < N; i++)
	{
		set<char> st;
		st.insert(i);
		for (int j = 0; j < N; j++)
		{
			if(Map[i][j] == 'Y')
			{
				if (st.find(j) == st.end())
				{
					st.insert(j);
				}
				for (int k = 0; k < N; k++)
				{
					if (Map[j][k] == 'Y')
					{
						if (st.find(k) == st.end())
						{
							st.insert(k);
						}
					}
				}
			}
		}
		output = max(output, (int)st.size() - 1);
	}
	cout << output;

	return 0;
}