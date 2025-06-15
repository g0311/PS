#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

bool Comp(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second != b.second)
	{
        return a.second > b.second;
    }
    else 
	{
        return a.first < b.first;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	map<string, int> Map;
	for (int i = 0; i < N; i++)
	{
		string book;
		cin >> book;
		if (Map.find(book) == Map.end())
		{
			Map[book] = 1;
		}
		else
		{
			Map[book]++;
		}
	}
	
	vector<pair<string, int>> arr(Map.begin(), Map.end());
	sort(arr.begin(), arr.end(), Comp);

	cout << arr[0].first;

	return 0;
}

