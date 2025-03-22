#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
#define endl '\n'

string A, B;
int nums[10];

string output;
bool DFS(int id)
{
	if (id == A.size())
	{
		int a = stoi(output);
		int b = stoi(B);
		if (a <= b)
			return true;
		else
			return false;
	}

	for (int i = 9; i >= 0; i--)
	{
		if (nums[i] > 0)
		{
			nums[i]--;
			output.push_back(i + 48);
			if (DFS(id + 1))
				return true;
			output.pop_back();
			nums[i]++;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	for (int i = 0; i < A.size(); i++)
	{
		int a = A[i] - 48;
		nums[a]++;
	}

	
	bool isEnd = DFS(0);
	if (isEnd)
	{
		if (output[0] == '0')
		{
			cout << -1;
			return 0;
		}
		else
		{
			cout << output;
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}


// 3   2   7    6
//1.5  1   7   7.5