#pragma once
#include <iostream>

using namespace std;

int cnt['z' + 1];
void solution() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char temp[30];
		cin >> temp;
		cnt[temp[0]]++;
	}

	bool flag = false;
	for (int i = 'a'; i <= 'z'; ++i)
	{
		if (cnt[i] >= 5)
		{
			cout << char(i);
			flag = true;
		}
	}
	if (!flag) cout << "PREDAJA";
}