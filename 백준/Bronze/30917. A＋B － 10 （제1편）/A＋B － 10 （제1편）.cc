#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//#define endl '\n'
#define ll long long
#define INF 2e9
#define FINF 1.7e308

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int resp;
    int A, B;
    for (int a = 1; a <= 9; a++) {
        cout << "? A " << a << endl;

        cin >> resp;

        if (resp == 1) {
            A = a;
            break;
        }
    }

    for (int b = 1; b <= 9; b++) {
        cout << "? B " << b << endl;

        cin >> resp;

        if (resp == 1) {
            B = b;
            break;
        }
    }

    cout << "! " << A + B;

	return 0;
}

/*
1 3 2 4
3 2 5 10

*/