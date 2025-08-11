#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int N;
		cin >> N;
		vector<string> arr(N);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		bool bValid = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				bool bChecked = false;
				for (int k = 0; k < arr[i].size(); k++)
				{
					if (arr[i][k] != arr[j][k])
					{
						bChecked = true;
						break;
					}
				}
				if (!bChecked)
				{
					bValid = false;
					break;
				}
			}
			if (!bValid)
			{
				break;
			}
		}
		cout << (bValid ? "YES" : "NO") << endl;
	}

    return 0;
}