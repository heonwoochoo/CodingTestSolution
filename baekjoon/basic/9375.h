#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, m;
long long result = 1;	// ����� ���� ���� Ŀ�� �� �ֱ⿡ long long���� �����ϴ� ���� ����
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
