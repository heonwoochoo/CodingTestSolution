#pragma once
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void solution() {
	int heights[9];
	for (auto& e : heights) cin >> e;
	sort(heights, heights + 9);
	do
	{
		int sum = 0;
		for (int i = 0; i < 7; ++i) sum += heights[i];
		if (sum == 100)
		{
			for (int i = 0; i < 7; ++i) cout << heights[i] << endl;
			break;
		}
	} while (next_permutation(heights, heights + 9));
}

void solution2() {
	array<int, 9> heights;
	for (auto& e : heights) cin >> e;

	sort(heights.begin(), heights.end());

	int hSum = 0;
	for (auto& e : heights) hSum += e;

	for (int i = 0; i < 8; ++i)
	{
		bool flag = false;
		for (int j = i + 1; j < 9; ++j)
		{
			if (hSum - heights[i] - heights[j] == 100)
			{
				for (auto& e : heights)
				{
					if (e != heights[i] && e != heights[j]) cout << e << endl;
				}
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
}