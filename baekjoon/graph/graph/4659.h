#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

string s;
array<char, 5> mo = { 'a', 'e', 'i', 'o', 'u' };

bool isMo(char c)
{
	if (find(mo.begin(), mo.end(), c) != mo.end()) return true;
	return false;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> s && s != "end")
	{
		string res = "acceptable.";
		bool check = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (!check)
			{
				if (isMo(s[i])) check = true;
				if (i == s.size() - 1 && !check)
				{
					res = "not acceptable.";
					break;
				}
			}
			
			if (s.size() > 1 && i < s.size() - 1 && s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
			{
				res = "not acceptable.";
				break;
			}
			
			if (s.size() > 2 && i < s.size() - 2)
			{
				if ((isMo(s[i]) && isMo(s[i + 1]) && isMo(s[i + 2])) ||
					(!isMo(s[i]) && !isMo(s[i + 1]) && !isMo(s[i + 2]))
					)
				{
					res = "not acceptable.";
					break;
				}
			}
		}
		
		cout << "<" << s << "> is " << res << '\n';
	}
}
