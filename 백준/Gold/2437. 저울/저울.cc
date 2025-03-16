#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> wts;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		wts.push_back(a);
	}
	sort(wts.begin(), wts.end());

	int sum = 0;
	int i;
	for (i = 0; i < wts.size(); i++)
	{
		if (sum + 1 < wts[i])
		{
			break;
		}
		sum += wts[i];
	}

	cout << sum + 1;
	return 0;
}

/*
1 1 2 3 6 7 30
1 2 4 7 13 20 
*/