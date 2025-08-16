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

	int N;
	cin >> N;
	set<string, greater<string>> names;
	for (int i = 0; i < N; i++)
	{
		string name, oper;
		cin >> name >> oper;
		if (oper == "enter")
		{
			names.insert(name);
		}
		else
		{
			names.erase(name);
		}
	}
	for (auto name : names)
	{
		cout << name << endl;
	}

    return 0;
}
