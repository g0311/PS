#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, output, temp;

	getline(cin, str);

	bool isR = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			if (!temp.empty())
			{
				for (int j = temp.size() - 1; j >= 0; j--)
				{
					output.push_back(temp[j]);
				}
				temp.clear();
			}
			output.push_back(str[i]);
			isR = true;
		}
		else if (str[i] == '>')
		{
			output.push_back(str[i]);
			isR = false;
		}
		else if (isR)
		{
			output.push_back(str[i]);
		}
		else
		{
			if (str[i] == ' ')
			{
				for (int j = temp.size() - 1; j >= 0; j--)
				{
					output.push_back(temp[j]);
				}
				temp.clear();
				output.push_back(' ');
			}
			else
			{
				temp.push_back(str[i]);
			}
		}
	}
	if (!temp.empty())
	{
		for (int j = temp.size() - 1; j >= 0; j--)
		{
			output.push_back(temp[j]);
		}
		temp.clear();
	}
	cout << output;

	return 0;
}