#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	string output;
	output.push_back(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			output.push_back(str[i + 1]);
		}
	}
	cout << output;

	return 0;
}