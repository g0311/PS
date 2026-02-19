#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 1e9
#define LLMAX 9'223'372'036'854'775'807

int N;
vector<int> Arr;
map<int, int> Map;
double Sum = 0;
int MaxCt = 0;

int Avr()
{
	if (Sum > 0)
	{
		return Sum / N + 0.5f;
	}
	else
	{
		return Sum / N - 0.5f;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	Arr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
		Sum += Arr[i];
		if (Map.find(Arr[i]) != Map.end())
		{
			Map[Arr[i]]++;
		}
		else
		{
			Map[Arr[i]] = 1;
		}

		if (MaxCt < Map[Arr[i]])
		{
			MaxCt = Map[Arr[i]];
		}
	}

	vector<int> Cts;
	for (auto iter : Map)
	{
		if(iter.second == MaxCt)
		{ 
			Cts.push_back(iter.first);
		}
	}
	sort(Cts.begin(), Cts.end());

	sort(Arr.begin(), Arr.end());
	cout 
		<< Avr() << " "
		<< Arr[N / 2] << " " 
		<< ((Cts.size() >= 2) ?  Cts[1] : Cts[0]) << " "
		<<Arr[N - 1] - Arr[0];

	return 0;
}
