#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, res;
string str;
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		stack<char> stk;
		cin >> str;
		for (auto& e : str)
		{
			if (stk.empty() || stk.top() != e) stk.push(e);
			else stk.pop();
		}
		!stk.size() && res++;
	}
	cout << res;
}
