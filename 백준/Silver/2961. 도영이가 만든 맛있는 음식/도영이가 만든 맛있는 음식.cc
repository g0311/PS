#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

vector<pair<int, int>> ing;

int output = INF;
void DFS(int k, long long current_sour, long long current_bitter, int selected_count)
{
    if (k == ing.size())
    {
        if (selected_count > 0)
        {
            output = min(output, (int)abs(current_sour - current_bitter));
        }
        return;
    }

    DFS(k + 1, current_sour * ing[k].first, current_bitter + ing[k].second, selected_count + 1);
    DFS(k + 1, current_sour, current_bitter, selected_count);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	ing.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ing[i].first >> ing[i].second;
	}
	DFS(0, 1, 0, 0);

	cout << output << endl;

	return 0;
}
