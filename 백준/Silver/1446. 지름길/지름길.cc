#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl '\n'
#define INF 2e9

vector<pair<int, int>> roads[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D;
    cin >> N >> D;
	for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
		roads[b].push_back({ a, c });
    }

    int Map[10001];
    for (int i = 0; i < 10000; i++)
    {
        Map[i] = INF;
    }

	Map[0] = 0;
    for (int i = 1; i <= D; i++)
    {
		if (roads[i].size() == 0)
		{
			Map[i] = Map[i - 1] + 1;
		}
		else
		{
            Map[i] = Map[i - 1] + 1;
			for (int j = 0; j < roads[i].size(); j++)
			{
				int bef = roads[i][j].first;
				int cost = roads[i][j].second;
				Map[i] = min(Map[i], Map[bef] + cost);
			}
		}
    }
	cout << Map[D] << endl;
    
    return 0;
}