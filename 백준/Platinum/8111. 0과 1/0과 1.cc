#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		if (N == 1)
		{
			cout << 1 << endl;
			continue;
		}
		vector<int> visited(N, 0);

		string str = "1";
		int strNo = 1;
		queue<pair<string, int>> q;
		q.push({ str,strNo });
		visited[strNo] = 1;
		while (!q.empty())
		{
			string str = q.front().first;
			int strNo = q.front().second;
			q.pop();

			if (str.size() > 100)
			{
				cout << "BRAK" << endl;
				break;
			}

			str.push_back('0');
			int str0No = (10 * strNo) % N;
			if (str0No == 0)
			{
				cout << str << endl;
				break;
			}
			if (visited[str0No] != 1)
			{
				q.push({ str,str0No });
				visited[str0No] = 1;
			}
			str.pop_back();

			str.push_back('1');
			int str1No = (10 * strNo + 1) % N;
			if (str1No == 0)
			{
				cout << str << endl;
				break;
			}
			if (visited[str1No] != 1)
			{
				q.push({ str,str1No });
				visited[str1No] = 1;
			}
			str.pop_back();
		}
	}

	return 0;
}
