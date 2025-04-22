#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<int> Parents;

int find(int cur)
{
	if (Parents[cur] == cur)
		return cur;
	else
		return Parents[cur] = find(Parents[cur]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int G, P;
	cin >> G >> P;
	vector<int> plane(P);
	
	for (int i = 0; i < P; i++)
	{
		cin >> plane[i];
	}
	
	Parents.resize(G + 1);
	for (int i = 0; i <= G; i++)
		Parents[i] = i;


	int output = 0;
	for (int i = 0; i < P; i++)
	{
		int nexGate = find(plane[i]);
		if (nexGate == 0)
		{
			break;
		}
		else
		{
			output++;
			Parents[nexGate] = find(nexGate - 1);
		}
	}
	cout << output;

	return 0;
}
