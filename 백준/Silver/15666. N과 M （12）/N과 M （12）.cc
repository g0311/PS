#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
#define endl '\n'

int N, M;
vector<int> arr;
set<vector<int>> visit;
vector<int> output;

void Solve(int id, int cnt)
{
	if (cnt == M)
	{
		if (visit.find(output) != visit.end())
			return;

		visit.insert(output);

		for (int i = 0; i < M; i++)
		{
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = id; i < N; i++)
	{
		output.push_back(arr[i]);
		Solve(i, cnt + 1);
		output.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	Solve(0, 0);

	return 0;
}