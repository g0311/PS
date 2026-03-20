#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define INF 2e9
#define LLMAX 9'223'372'036'854'775'807
#define MOD 1'000'000'007

double Dist(double Ax, double Ay, double Az, double Bx, double By, double Bz)
{
	return sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2) + pow(Bz - Az, 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
	cin >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Cx >> Cy >> Cz;

	double ABx = Bx - Ax;
	double ABy = By - Ay;
	double ABz = Bz - Az;

	double ACx = Cx - Ax;
	double ACy = Cy - Ay;
	double ACz = Cz - Az;

	double dot = ABx * ACx + ABy * ACy + ABz * ACz;
	double lenSq = ABx * ABx + ABy * ABy + ABz * ABz;

	double t;
	if (lenSq == 0) 
	{
		t = -1;
	}
	else 
	{
		t = dot / lenSq;
	}

	double out;
	if (t < 0) 
	{
		out = Dist(Ax, Ay, Az, Cx, Cy, Cz);
	}
	else if (t > 1) 
	{
		out = Dist(Bx, By, Bz, Cx, Cy, Cz);
	}
	else 
	{
		double Px = Ax + t * ABx;
		double Py = Ay + t * ABy;
		double Pz = Az + t * ABz;
		out = Dist(Px, Py, Pz, Cx, Cy, Cz);
	}
	cout << fixed << setprecision(10) << out << endl;

	return 0;
}