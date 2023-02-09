#pragma once
#include <iostream>
#include <string>
using namespace std;

void solution() {
	string str;
	getline(cin, str);
	cout << str << endl;
	
	for (auto& e : str)
	{
		if (isalpha(e))
		{
			int tmp = e + 13;
			if ((isupper(e) && tmp > 'Z') || (islower(e) && tmp > 'z')) cout << char(tmp - 26);
			else cout << char(tmp);
		}
		else
		{
			cout << e;
		}
	}
}
