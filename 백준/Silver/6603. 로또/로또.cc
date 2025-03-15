#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<int> num;
int visit[13];
vector<int> output;

void DFS(int id, int ct)
{
	if (ct == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = id; i < num.size(); i++)
	{
		output.push_back(num[i]);
		DFS(i + 1, ct + 1);
		output.pop_back();
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
			return 0;

		num.clear();
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < k; i++)
		{
			int no;
			cin >> no;
			num.push_back(no);
		}
		sort(num.begin(), num.end());

		DFS(0,0);
		cout << endl;
	}

	return 0;
}