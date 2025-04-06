
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'
#define INF 2e9

vector<int> ps[200'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int deadLine, cupRamen;
        cin >> deadLine >> cupRamen;
		ps[deadLine].push_back(cupRamen);
    }

    int output = 0;
    priority_queue<int> pq;
    for (int curTime = N; curTime > 0; curTime--)
    {
		for (int i = 0; i < ps[curTime].size(); i++)
		{
			pq.push(ps[curTime][i]);
		}

        if (pq.empty())
			continue;
        
        output += pq.top();
        pq.pop();
    }

    cout << output;
    return 0;
}