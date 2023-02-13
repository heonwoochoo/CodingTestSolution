#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


string str, result;
map<char,int> mp;
int odd;
char mid;

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;

	for (auto& e : str) mp[e] ? mp[e]++ : mp[e] = 1;

	for (auto& e : mp)
	{
		if (e.second == 1) {
			odd++;
			mid = e.first;
		}
		else
		{
			if (e.second % 2)
			{
				odd++;
				mid = e.first;
			}
			for (int i = 0; i < e.second / 2; ++i) result += e.first;
		}

		if (odd > 1)
		{
			cout << "I'm Sorry Hansoo";
			break;
		}
	}
	if (odd == 1 || odd == 0)
	{
		cout << result;
		mid && cout << mid;
		reverse(result.begin(), result.end());
		cout << result << '\n';
	}
}
