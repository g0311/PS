#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>arr(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	list<int> output;
	for (int i = N; i >= 1; i--)
	{
		auto iter = output.begin();
		advance(iter, arr[i]);
		output.insert(iter, i);
	}

	for (auto iter = output.begin(); iter != output.end(); iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}