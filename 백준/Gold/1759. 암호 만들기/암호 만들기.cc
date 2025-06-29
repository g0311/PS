#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'000

int L, C;
vector<char> v;
string result;
void DFS(int id)
{
	if (id == L)
	{
		// Check if the current result is valid
		int consonants = 0, vowels = 0;
		for (char c : result)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				vowels++;
			else
				consonants++;
		}
		if (vowels >= 1 && consonants >= 2) // At least one vowel and two consonants
		{
			cout << result << endl;
		}
		return;
	}

	for (int i = id; i < C; i++)
	{
		if (id > 0 && result[id - 1] >= v[i]) continue; // Ensure lexicographical order
		result += v[i];
		DFS(id + 1);
		result.pop_back(); // Backtrack
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> L >> C;
	v.resize(C);
	for (int i = 0; i < C; i++)
	{
		cin >> v[i];
	}	
	sort(v.begin(), v.end());
	DFS(0);

	return 0;
}