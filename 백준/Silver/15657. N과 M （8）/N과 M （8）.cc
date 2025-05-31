#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int N, M;
vector<int> arr;
vector<int> temp;
set<vector<int>> st;

void Solve(int id, int ct)
{
	if (ct == M)
	{
		if (st.find(temp) == st.end())
		{
			st.insert(temp);
			for (int i = 0; i < M; i++)
			{
				cout << temp[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = id; i < N; i++)
	{
		temp.push_back(arr[i]);
		Solve(i, ct + 1);
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	Solve(0, 0);


	return 0;
}