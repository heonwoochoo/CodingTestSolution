#pragma once
#include <iostream>
#include <utility>
using namespace std;

int n, m, k, tmp, res, d;
pair<int, int> pos;

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	pos = { 1, m };
	for (int i = 0; i < k; ++i)
	{
		cin >> tmp;
		if (tmp < pos.first)
		{
			d = pos.first - tmp;
			pos = { pos.first - d, pos.second - d };
		}
		else if (tmp > pos.second)
		{
			d = tmp - pos.second;
			pos = { pos.first + d, pos.second + d };
		}
		res += d;
		d = 0;
	}
	cout << res;
}
