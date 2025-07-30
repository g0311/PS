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
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N, 0);
	vector<int> Vis(N, 0);
	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		int target = arr[i];

		int st = 0;
		int ed = N - 1;
		while (st < ed)
		{
			if (st == i) { st++; continue; }
			if (ed == i) { ed--; continue; }
			
			int sum = arr[st] + arr[ed];
			if (target == sum)
			{
				Vis[i] = 1;
				st++;
			}
			else if (sum > target)
			{
				ed--;
			}
			else
			{
				st++;
			}
		}
	}
	
	int out = 0;
	for (int i = 0; i < N; i++)
	{
		if (Vis[i] == 1)
		{
			out++;
		}
	}
	cout << out << endl;

	return 0;
}