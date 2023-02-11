#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, m;
long long result = 1;	// 경우의 수는 값이 커질 수 있기에 long long으로 선언하는 것이 좋음
string name, cate;
map<string, int> mp;

void sol(int m, map<string, int>& mp)
{
	for (auto& e : mp) result *= e.second + 1;
	result--;
	mp.clear();
	cout << result << '\n';
}


void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> name >> cate;
			mp[cate]++;
		}
		result = 1;
		sol(m, mp);
	}
}
