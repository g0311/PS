#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <set>
#include <queue>

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

    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strs[i];
    }

    int out = 0;
    for (int i = 0; i < n; ++i) 
{
        for (int j = i + 1; j < n; ++j) 
        {
            string& s1 = strs[i];
            string& s2 = strs[j];

            bool similar = true;
            int m1[26], m2[26];
            for (int k = 0; k < 26; ++k) 
            {
                m1[k] = m2[k] = -1;
            }

            for (int k = 0; k < s1.length(); ++k) 
            {
                int c1 = s1[k] - 'a';
                int c2 = s2[k] - 'a';

                if (m1[c1] == -1 && m2[c2] == -1) 
                {
                    m1[c1] = c2;
                    m2[c2] = c1;
                }
                else if (m1[c1] != c2 || m2[c2] != c1) 
                {
                    similar = false;
                    break;
                }
            }
            if (similar)
            {
                out++;
            }
        }
    }

    cout << out << endl;

    return 0;
}
