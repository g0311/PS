#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define INF 1e9

struct Dice
{
	int x1 = 0; // Left
	int x2 = 0; // Right
	int y1 = 0; // Top
	int y2 = 0; // Bottom
	int z1 = 0; // Front
	int z2 = 0; // Back

	void roll(int id, int& num)
	{
		int temp;
		switch (id)
		{
		case 1: //동
			temp = x2;
			x2 = y2;
			y2 = x1;
			x1 = y1;
			y1 = temp;
			break;
		case 2: //서
			temp = x1;
			x1 = y2;
			y2 = x2;
			x2 = y1;
			y1 = temp;
			break;
		case 4: //남
			temp = z2;
			z2 = y1;
			y1 = z1;
			z1 = y2;
			y2 = temp;
			break;
		case 3: //북
			temp = z1;
			z1 = y1;
			y1 = z2;
			z2 = y2;
			y2 = temp;
			break;
		}

		if (num == 0)
		{
			num = y2;
		}
		else
		{
			y2 = num;
			num = 0;
		}
	}
};

int Map[20][20];
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, M, Y, X, Ct;
	cin >> N >> M >> Y >> X >> Ct;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	Dice dice;
	for (int i = 0; i < Ct; i++)
	{
		int oper;
		cin >> oper;
		int ny = Y + dy[oper];
		int nx = X + dx[oper];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		dice.roll(oper, Map[ny][nx]);
		cout << dice.y1 << endl;
		Y = ny;
		X = nx;
	}

	return 0;
}