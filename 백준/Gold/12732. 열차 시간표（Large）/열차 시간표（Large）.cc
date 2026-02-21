#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for(int TC = 1; TC <= N; ++TC)
	{
		int T, NA, NB;
		cin >> T >> NA >> NB;
		list<pair<pii,pii>> ATime;
		for (int i = 0; i < NA; ++i)
		{
			pii t1, t2; char temp;
			cin >> t1.first >> temp >> t1.second;
			cin >> t2.first >> temp >> t2.second;
			ATime.push_back({t1, t2});
		}
		ATime.sort();

		list<pair<pii, pii>> BTime;
		for (int i = 0; i < NB; ++i)
		{
			pii t1, t2; char temp;
			cin >> t1.first >> temp >> t1.second;
			cin >> t2.first >> temp >> t2.second;
			BTime.push_back({ t1, t2 });
		}
		BTime.sort();

		int AOut = 0, BOut = 0;
		while (!ATime.empty() && !BTime.empty())
		{
			pair<pii, pii> A = *(ATime.begin());
			pair<pii, pii> B = *(BTime.begin());
			
			list<pair<pii, pii>>* CurTrack = (A < B ? &ATime : &BTime);
			list<pair<pii, pii>>* NexTrack = (A < B ? &BTime : &ATime);

			pair<pii, pii> CurWay = (A < B ? A : B);

			CurTrack->erase(CurTrack->begin());
			AOut += (A < B ? 1 : 0);
			BOut += (A < B ? 0 : 1);

			bool bIsEnd = false;
			while (!bIsEnd)
			{
				bIsEnd = true;
				pii EndTime = CurWay.second;
				EndTime.second += T;
				if (EndTime.second >= 60)
				{
					++EndTime.first;
					EndTime.second -= 60;
				}
				for (auto iter = NexTrack->begin(); iter != NexTrack->end(); iter++)
				{
					if (iter->first >= EndTime)
					{
						CurWay = *iter;
						NexTrack->erase(iter);
						swap(CurTrack, NexTrack);
						bIsEnd = false;
						break;
					}
				}
			}
		}
		AOut += ATime.size();
		BOut += BTime.size();
		cout << "Case #" << TC << ": " << AOut << " " << BOut << endl;
	}

	return 0;
}

/*
AB 중 하나가 비기 전까지
{
	AB 중 가장 작은 시작 열차 선택
	{
		해당 시작 열차의 END Time으로 부터 가장 가까운 다른 역 열차 선택 + 지우기
		해당 시작 열차의 END Time으로 부터 가장 가까운 다른 역 열차 선택 + 지우기
		해당 시작 열차의 END Time으로 부터 가장 가까운 다른 역 열차 선택 + 지우기
	}
}
*/