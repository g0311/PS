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

int N, K;
set<char> chars;
vector<string> words;
int output = 0;

void DFS(int idx, int ct)
{
	if (ct == K)
	{
		int count = 0;
		for (string word : words)
		{
			bool canRead = true;
			for (char c : word)
			{
				if (chars.find(c) == chars.end())
				{
					canRead = false;
					break;
				}
			}
			if (canRead)
			{
				count++;
			}
		}
		output = max(output, count);
		return;
	}

	for (int i = idx; i < 26; i++)
	{
		if ('a' + i == 'a' || 'a' + i == 'c' || 'a' + i == 'i' || 'a' + i == 'n' || 'a' + i == 't')
		{
			continue;
		}

		chars.insert('a' + i);
		DFS(i + 1, ct + 1);
		chars.erase('a' + i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	words.resize(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> words[i];
	}
	if (K < 5)
	{
		cout << 0 << endl;
		return 0;
	}

	chars.insert('a');
	chars.insert('c');
	chars.insert('i');
	chars.insert('n');
	chars.insert('t');
	DFS(0, 5);
	
	cout << output << endl;

	return 0;
}