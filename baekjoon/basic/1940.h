#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp, res;
vector<int> vec;
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (vec[i] + vec[j] == m)
			{
				res++;
				break;
			}
			else if (vec[i] + vec[j] > m) break;
		}
	}
	cout << res;
}
