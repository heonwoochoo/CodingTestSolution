#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, c, tmp;
map<int, int> mp;
vector<pair<int,int>> vec;
vector<int> f;

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (find(f.begin(), f.end(), tmp) == f.end()) f.push_back(tmp);
		mp[tmp] = mp[tmp] ? mp[tmp] + 1 : 1;
	}
	for (auto& e : mp) vec.push_back({ e.first, e.second });
	
	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
		{
			return find(f.begin(), f.end(), a.first) < find(f.begin(), f.end(), b.first);
		}
		else return a.second > b.second;
		});

	for (auto& e : vec)
	{
		for (int i = 0; i < e.second; ++i) cout << e.first << " ";
	}
}
