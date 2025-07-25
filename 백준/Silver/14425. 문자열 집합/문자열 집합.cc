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
#define INF 1e9


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	set<string> st;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		st.insert(s);
	}

	int output = 0;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (st.find(s) != st.end())
			output++;
	}
	cout << output << endl;

	return 0;
}