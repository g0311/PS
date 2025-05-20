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

	int N, M;
	cin >> N >> M;
	vector<string>arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int output = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 1; i + k < N && j + k < M; k++) 
			{
				if (i + k < N && j + k < M)
				{
					if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
					{
						output = max(output, (k+1)*(k+1));
					}
				}
			}
		}
	}
	cout << output;

	return 0;
}
