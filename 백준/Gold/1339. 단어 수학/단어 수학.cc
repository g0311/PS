#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

int chars[26];

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<string> words(N);
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
		int v = 1;
		for (int j = words[i].size() - 1; j >= 0; j--)
		{
			chars[words[i][j] - 'A'] += v;
			v *= 10;
		}
	}
	sort(chars, chars + 26, comp);

	map<int, int> Map;
	int no = 9;
	int output = 0;
	for (int i = 0; i < 26; i++)
	{
		if (chars[i] == 0)
		{
			break;
		}
		else
		{
			output += chars[i] * no;
			no--;
		}
	}
	cout << output;
	return 0;
}
