
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define endl '\n'
#define INF 2e9


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cur = 1;
    int curNo = 666;
    while (cur != N)
    {
        curNo++;
		string s = to_string(curNo);
		if (s.find("666") != string::npos)
		{
			cur++;
		}
    }
    cout << curNo << endl;

    return 0;
}