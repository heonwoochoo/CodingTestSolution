#pragma once
#include<iostream>
#include<string>
using namespace std;

int n;
int solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int num = 666;
	for (;; num++)
	{
		if (to_string(num).find("666") != string::npos) --n;
		if (n == 0) break;
	}
	cout << num;

	return 0;
}