#pragma once
#include <iostream>
#include <string>
using namespace std;

void solution() {
	string str;
	cin >> str;

	bool result = true;
	for (int i = 0; i < str.length() / 2; ++i)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			result = false;
			break;
		}
	}
	cout << result;
}

void solution2()
{
	string str;
	cin >> str;
	string str_copy = str;
	reverse(str.begin(), str.end());
	if (str == str_copy) cout << 1;
	else cout << 0;
}