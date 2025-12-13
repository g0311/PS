#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> holes(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> holes[i];
	}

	queue<int> sliding;
	ll out = 0;
	ll sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sliding.push(holes[i]);
		sum += holes[i];
		while (sum > M)
		{
			sum -= sliding.front(); sliding.pop();
		}
		out = max(out, sum);
	}

	cout << out;
	
	return 0;
}