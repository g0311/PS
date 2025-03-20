#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl '\n'

float Dist(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;

	int output = 0;
	for (int i = 0; i < P; i++)
	{
		int x, y;
		cin >> x >> y;

		if (x >= X && x <= X + W && y >= Y && y <= Y + H)
		{
			output++;
			continue;
		}
		
		if (Dist(x, y, X, Y + H / 2.f) <= H / 2.f)
		{
			output++;
			continue;
		}

		if (Dist(x, y, X + W, Y + H / 2.f) <= H / 2.f)
		{
			output++;
			continue;
		}
	}
	cout << output;

	return 0;
}