#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> bID;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'b')
			bID.push_back(i);
	}
	if (bID.size() == 0)
	{
		cout << 0;
		return 0;
	}

	int output = 1001;
	for (int i = 0; i < bID.size(); i++)
	{
		int curBCount = bID.size() - 1; int id = i;
		int befID = bID[id], curID;
		id = (id + 1 + bID.size()) % bID.size();
		int curOutput = 0;
		while (curBCount > 0)
		{
			curID = bID[id];
			curBCount--;
			if (curID != (befID + 1 + str.size()) % str.size())
			{
				curOutput++;
				curID = (befID + 1 + str.size()) % str.size();
			}
			else
			{
				id = (id + 1 + bID.size()) % bID.size();
			}
			befID = curID;
			if (output < curOutput)
				break;
		}
		output = min(curOutput, output);
	}

	for (int i = 0; i < bID.size(); i++)
	{
		int curBCount = bID.size() - 1; int id = i;
		int befID = bID[id], curID;
		id = (id - 1 + bID.size()) % bID.size();
		int curOutput = 0;
		while (curBCount > 0)
		{
			curID = bID[id];
			curBCount--;
			if (curID != (befID - 1 + str.size()) % str.size())
			{
				curOutput++;
				curID = (befID - 1 + str.size()) % str.size();
			}
			else
			{
				id = (id - 1 + bID.size()) % bID.size();
			}
			befID = curID;
			if (output < curOutput)
				break;
		}
		output = min(curOutput, output);
	}

	cout << output;
	return 0;
}