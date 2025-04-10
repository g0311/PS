
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define endl '\n'
#define INF 2e9


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    
    string substr;
    int num = 0;
	bool isPlus = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-')
        {
            substr += str[i];
        }
        else
        {
            if(isPlus)
    			num += stoi(substr);
			else
				num -= stoi(substr);
            substr.clear();

            if (str[i] == '-')
                isPlus = false;
        }
    }

    if (isPlus)
        num += stoi(substr);
    else
        num -= stoi(substr);
    substr.clear();

    cout << num;


    return 0;
}