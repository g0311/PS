#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int N, M;
vector<int> nums;
vector<int> output;
set<vector<int>> st;
void Solve(int id, int ct)
{
	if (ct == M)
	{
		if(st.find(output) == st.end())
		{
			for (int i = 0; i < M; i++)
			{
				cout << output[i] << " ";
			}
			cout << endl;
			st.insert(output);
		}
		return;
	}
	for (int i = id; i < N; i++)
	{
		output.push_back(nums[i]);
		Solve(i + 1, ct + 1);
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
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	
	Solve(0, 0);

	return 0;
}
