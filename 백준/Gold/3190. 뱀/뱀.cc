#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
int Map[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a][b] = 8;
	}
	int L;
	cin >> L;
	map<int, char> info;
	for (int i = 0; i < L; i++)
	{
		int a; char b;
		cin >> a >> b;
		info.insert({ a,b });
	}
	Map[1][1] = 1; //1234 동남서북
	int dx[] = { 1,0,-1,0 }; //0123 동남서북
	int dy[] = { 0,1,0,-1 };
	//뱀 범위 : 1 ~ N-2
	pair<int, int> headPos = { 1,1 };
	pair<int, int> tailPos = { 1,1 };

	//1. info 읽고 머리 방향 바꾸기
	//2. 머리 이동 시키기
	//3. 사과 확인하기
	//4. 없으면 꼬리 이동시키기
	
	int output = 0;
	while (true)
	{
		int y = headPos.first; int x = headPos.second;
		int curDir = Map[y][x] - 1;
		
		y = y + dy[curDir];
		x = x + dx[curDir];

		output++;

		if (y <= 0 || y > N || x <= 0 || x > N)
			break;
		if (Map[y][x] != 0 && Map[y][x] != 8)
			break;

		if(Map[y][x] != 8)
		{
			int ty = tailPos.first; int tx = tailPos.second;
			int tdir = Map[ty][tx] - 1;
			tailPos.first = ty + dy[tdir];
			tailPos.second = tx + dx[tdir];

			Map[ty][tx] = 0;
		}
		Map[y][x] = curDir + 1;

		headPos.first = y;
		headPos.second = x;

		if (info.find(output) != info.end())
		{
			if (info[output] == 'L')
			{
				Map[y][x] = (curDir + 3) % 4 + 1;
			}
			else
			{
				Map[y][x] = (curDir + 1) % 4 + 1;
			}
		}
		curDir = Map[y][x] - 1;
	}

	cout << output;
	return 0;
}

/*
1 1 3 7 8
  1 3 6

*/