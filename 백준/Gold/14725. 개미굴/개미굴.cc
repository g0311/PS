#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'
#define ll long long
#define INF 1'000'000'007

struct Node
{
	string str;
	map<string, Node*> childs;
	Node() : str("") {}
	Node(string s) : str(s) {}
};

void printTree(const Node& node, int depth)
{
	if(depth >= 0)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << "--";
		}
		cout << node.str;
		cout << endl;
	}
	for (auto child : node.childs)
	{
		printTree(*child.second, depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Node Root;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int ct;
		cin >> ct;
		Node* curNode = &Root;
		for (int j = 0; j < ct; j++)
		{
			string str;
			cin >> str;
			auto It = curNode->childs.find(str);
			if (It == curNode->childs.end())
			{
				curNode->childs.emplace(str, new Node(str));
				curNode = curNode->childs[str];
			}
			else
			{
				curNode = It->second;
			}
		}
	}
	printTree(Root, -1);
	
	return 0;
}

/*
   4   4 
 5 1 2 6 5
   3   3
*/