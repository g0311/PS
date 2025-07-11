#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1e9


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> output;
	for (int i = 0; i < n; i++)
	{
		int p, l;
		cin >> p >> l;
		vector<int> v;
		for (int j = 0; j < p; j++)
		{
			int t;
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(), v.end(), greater<>());
		int Pt;
		if (v.size() < l)
			Pt = 1;
		else
			Pt = v[l - 1];

		output.push_back(Pt);
	}
	sort(output.begin(), output.end());

	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < output.size(); i++)
	{
		if (sum + output[i] > m)
			break;
		sum += output[i];
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}