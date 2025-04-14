#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<ll> arr;
string str;
void Solve(int bef)
{
	if(!str.empty())
		arr.push_back(stoll(str));
	
	for (int i = bef - 1; i >= 0; i--)
	{
		str.push_back('0' + i);
		Solve(i);
		str.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X;
	cin >> X;

	Solve(10);
	sort(arr.begin(), arr.end());
	
	if (arr.size() <= X)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << arr[X] << endl;
	}

	return 0;
}
