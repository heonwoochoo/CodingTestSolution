#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> st;

int res[1000004], a[1000004];

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	

	memset(res, -1, sizeof(res));

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		while (st.size() && a[st.top()] < a[i])
		{
			res[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}
}