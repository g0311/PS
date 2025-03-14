#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'

vector<int> map[100001];
int output[100001];
int visited[100001];

void DFS(int idx)
{
	visited[idx] = 1;
	output[idx] = 1;
	
	for (int i = 0; i < map[idx].size(); i++)
	{
		int nex = map[idx][i];
		if (visited[nex] == 1)
			continue;

		DFS(nex);
		output[idx] += output[nex];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	DFS(R);

	for (int i = 0; i < Q; i++)
	{
		int X;
		cin >> X;
		cout << output[X] << endl;
	}


	return 0;
}