
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int Path[1'000'001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int,int>> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	vector<pair<int,int>>output;
	memset(Path, -1, sizeof(Path));
	for (int i = 0; i < N; i++)
	{
		auto iter = lower_bound(output.begin(), output.end(), make_pair(arr[i].first, -1));
		if (iter == output.end())
		{
			output.push_back({ arr[i].first, i });
			if (output.size() > 1)
				Path[i] = output[output.size() - 2].second;
		}
		else
		{
			*iter = { arr[i].first, i };
			if (iter != output.begin())
				Path[i] = (iter - 1)->second;
		}
	}

	cout << output.size() << endl;
	int num = output[output.size() - 1].second;
	stack<int> st;
	while (num != -1)
	{
		st.push(arr[num].first);
		num = Path[num];
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}

/*
1245
12435
1235
1245
*/