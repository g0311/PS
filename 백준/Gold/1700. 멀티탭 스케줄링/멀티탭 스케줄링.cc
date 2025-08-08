#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<int> arr(K);
	for(int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}

	int out = 0;
	set<int> st;
	for (int i = 0; i < K; i++)
	{
		if (st.find(arr[i]) != st.end())
			continue;

		if (st.size() >= N)
		{
			int target = -1;
			int LastPos = -1;
			for (auto X : st)
			{
				int Pos = -1;
				for (int j = i; j < K; j++)
				{
					if (X == arr[j])
					{
						Pos = j;
						break;
					}
				}
				if (Pos == -1)
				{
					target = X;
					break;
				}
				else if (Pos > LastPos)
				{
					target = arr[Pos];
					LastPos = Pos;
				}
			}
			
			st.erase(target);
			out++;
		}

		st.insert(arr[i]);
	}
	
	cout << out;

	return 0;
}