#pragma once
#include <iostream>
#include <vector>

using namespace std;

void solution() {
	int n, k, sum_max = 0, slide = 0;
	vector<int> d;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		d.push_back(tmp);
	}

	for (int i = 0; i < k; ++i) slide += d[i];
	sum_max = slide;

	for (int i = 1; i <= n - k; ++i)
	{
		slide = slide - d[i - 1] + d[i + k - 1];
		sum_max = max(sum_max, slide);
	}

	cout << sum_max;
}
