#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

vector<set<int>> In;
vector<set<int>> Out;
vector<int> output;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	In.resize(N + 1);
	Out.resize(N + 1);
	output.resize(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		In[B].insert(A);
		Out[A].insert(B);
	}

	queue<int> Q1;
	queue<int> Q2;
	int curID = 2;
	for (int i = 1; i <= N; ++i)
	{
		if (In[i].empty())
		{
			Q1.push(i);
			output[i] = 1;
		}
	}

	while (!Q1.empty())
	{
		int curSj = Q1.front(); Q1.pop();
		for (auto nexSj : Out[curSj])
		{
			In[nexSj].erase(curSj);
			if (In[nexSj].empty())
			{
				Q2.push(nexSj);
				output[nexSj] = curID;
			}
		}

		if (Q1.empty())
		{
			Q1 = move(Q2);
			curID++;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << output[i] << " ";
	}

	return 0;
}