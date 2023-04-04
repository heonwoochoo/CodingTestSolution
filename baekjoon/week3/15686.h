#pragma once
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, m, tmp;
vector<pair<int, int>> HomeList;
vector<pair<int, int>> ChickList;


void solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> tmp;
			if (tmp == 1) HomeList.emplace_back(make_pair(i, j));
			else if (tmp == 2) ChickList.emplace_back(make_pair(i, j));
		}
	}

	// 생존한 치킨집

}