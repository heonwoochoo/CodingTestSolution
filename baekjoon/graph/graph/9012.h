#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string s;

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		
		stack<char> st;
		for (auto& e : s)
		{
			if (e == '(') st.emplace(e);
			else
			{
				if (st.empty())
				{
					st.emplace(e);
					break;
				}
				else st.pop();
			}
		}

		if (st.size() == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
