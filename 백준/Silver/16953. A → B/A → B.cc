#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
#define endl '\n'
#define MAX 1'000'000'000

int a, b;
int output = MAX;

void Solve(int curNo, int cnt)
{
	if (curNo == a)
	{
		output = min(output, cnt);
		return;
	}
	else if (curNo < a)
	{
		return;
	}

	int fNo = curNo % 10;
	if (fNo == 1)
	{
		int nexNo = (curNo - fNo) / 10;
		Solve(nexNo, cnt + 1);
	}
	if (curNo % 2 == 0)
	{
		int nexNo = curNo / 2;
		Solve(nexNo, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	Solve(b, 0);

	if (output == MAX)
		cout << -1;
	else
		cout << output + 1;

	return 0;
}