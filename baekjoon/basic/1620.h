#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
map<string, int> map1;
map<int, string> map2;
string tmp;
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		map1[tmp] = i + 1;
		map2[i + 1] = tmp;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		if (atoi(tmp.c_str()) == 0)
		{
			cout << map1[tmp] << '\n';
		}
		else
		{
			cout << map2[atoi(tmp.c_str())] << '\n';
		}
	}
}
