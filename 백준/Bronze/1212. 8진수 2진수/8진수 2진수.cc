#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string output;
	for (int i = 0; i < str.size(); i++)
	{
		int ch = str[i] - 48;
		if (ch >= 4)
		{
			output.push_back('1');
			ch -= 4;
		}
		else
		{
			output.push_back('0');
		}

		if (ch >= 2)
		{
			output.push_back('1');
			ch -= 2;
		}
		else
		{
			output.push_back('0');
		}

		if (ch >= 1)
		{
			output.push_back('1');
			ch -= 1;
		}
		else
		{
			output.push_back('0');
		}
	}

	int id = 0;
	while (id < output.size() && output[id] == '0')
	{
		id++;
	}
	if (id == output.size())
	{
		cout << 0;
		return 0;
	}

	for (int i = id; i < output.size(); i++)
	{
		cout << output[i];
	}

	return 0;
}

/*
7
4 2 1
6
4 2 0
5
4 0 1
4
4 0 0
3
0 2 1
2
0 2 0
1
0 0 1
0
0 0 0

*/