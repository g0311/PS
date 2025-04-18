
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
	cin >> N;
	vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<int> output;
    stack<int> stk;
    for (int i = N - 1; i >= 0; i--)
    {
		while (!stk.empty() && stk.top() <= arr[i])
		{
			stk.pop();
		}
        if (stk.empty())
        {
			output.push_back(-1);
        }
        else
        {
			output.push_back(stk.top());
        }
		stk.push(arr[i]);
    }


	for (int i = output.size() - 1; i >= 0; i--)
	{
		cout << output[i] << " ";
	}

    return 0;
}