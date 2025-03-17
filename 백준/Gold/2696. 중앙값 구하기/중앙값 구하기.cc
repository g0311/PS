#include <iostream>
#include <vector>
#include <cmath>
#include <list>

using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int M;
        cin >> M;
        list<int> arr;
        vector<int> output;
        for (int i = 0; i < M; i++)
        {
            int a;
			cin >> a;
            auto iter = lower_bound(arr.begin(), arr.end(), a);
			arr.insert(iter, a);
            if (i % 2 == 0)
            {
				auto mid_iter = next(arr.begin(), i / 2);
                output.push_back(*mid_iter);
            }
        }
        
		cout << output.size() << endl;
		for (int i = 0; i < output.size(); i++)
		{
			cout << output[i] << " ";
			if (i % 10 == 9)
				cout << endl;
		}
        cout << endl;
    }

    return 0;
}