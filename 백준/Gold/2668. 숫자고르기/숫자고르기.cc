
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9

vector<int> arr;
int visited[101];
int visited2[101];
void DFS(int cur, int For)
{
    visited[cur] = 1;
    if (visited[arr[cur]] != 1)
    {
		DFS(arr[cur], For);
    }
    else if(arr[cur] == For)
    {
        visited[For] = -1;
        return;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    arr.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int output = 0;
	vector<int> outArr;
    for (int i = 1; i <= N; i++)
    {
        if (visited2[i] == 1)
            continue;

		memset(visited, 0, sizeof(visited));
        DFS(i, i);
		if (visited[i] == -1)
		{
            for (int i = 1; i <= N; i++)
            {
                if (visited[i] != 0)
                {
                    output++;
					outArr.push_back(i);
                    visited2[i] = 1;
                }
            }
		}
    }
	sort(outArr.begin(), outArr.end());
	cout << output << endl;
	for (int i : outArr)
	{
		cout << i << endl;
	}

    return 0;
}

/*
1 3 6 6 7 9

3 6 7 8 10 12 14 15 18 20

1 2 5
2 5 2
*/