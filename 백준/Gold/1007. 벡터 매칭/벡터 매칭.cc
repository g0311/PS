#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

int xSum, ySum;
double minOutput;
vector<pair<int,int>> tmp;

void Solve(vector<pair<int, int>> arr, int count, int max, int bef)
{
	if (count == max)
	{
		int xT = 0, yT = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			xT += tmp[i].first;
			yT += tmp[i].second;
		}
		xT *= 2; yT *= 2;
		double tmp = sqrtl(pow(xSum - xT, 2) + pow(ySum - yT, 2));
		minOutput = min(minOutput, tmp);
		return;
	}

	for (int i = bef + 1; i < arr.size(); i++)
	{
		tmp.push_back(arr[i]);
		Solve(arr, count + 1, max, i);
		tmp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;
	while(TC--)
	{
		int N;
		cin >> N;
		vector<pair<int, int>> arr(N);
		xSum = 0, ySum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].first >> arr[i].second;
			xSum += arr[i].first;
			ySum += arr[i].second;
		}

		minOutput = INF;
		Solve(arr, 0, N / 2, -1);
		cout << fixed;
		cout.precision(12);
		cout << minOutput << endl;
	}


	return 0;
}
