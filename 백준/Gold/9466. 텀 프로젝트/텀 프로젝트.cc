#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<int>arr;
int Visited[100001];
map<int, int> Map;

int Solve(int cur, int id)
{
	if (Map.find(cur) != Map.end())
	{
		return(id - Map[cur]);
	}
	else if (Visited[cur] == 1)
	{
		return 0;
	}
	else
	{
		Map[cur] = id;
		Visited[cur] = 1;
		return Solve(arr[cur], id + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int N;
		cin >> N;
		arr.resize(N + 1);
		memset(Visited, 0, sizeof(Visited));
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		
		int output = 0;
		for (int i = 1; i <= N; i++)
		{
			if (Visited[i] == 0)
			{
				output += Solve(i, 0);
				Map.clear();
			}
		}

		cout << N - output << endl;
	}

	return 0;
}

/*
그래프 안만들어지는 애만 찾기
십만...
*/