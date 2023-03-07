#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		stack<char> st;
		getline(cin, s);
		if (s == ".") break;
		for (auto& e : s)
		{
			if (e == '[' || e == '(')
			{
				st.emplace(e);
			}
			else if (e == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					st.emplace(e);
					break;
				}
				st.pop();
			}
			else if (e == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					st.emplace(e);
					break;
				}
				st.pop();
			}
		}
		if (st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}
