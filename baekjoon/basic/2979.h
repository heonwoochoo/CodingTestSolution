#pragma once
#include <iostream>
#include <utility>
#include <array>
#include <cmath>
using namespace std;

bool isParking(pair<int, int> timeRange, int time)
{
	return (time >= timeRange.first && time < timeRange.second);
}

void solution() {
	int totalCharge = 0;
	int charge[3];
	int minT = INT_MAX;
	int maxT = INT_MIN;
	for (auto& e : charge) cin >> e;

	array<pair<int, int>, 3> timeRanges;

	for (auto& e : timeRanges)
	{
		cin >> e.first >> e.second;
		minT = min(minT, e.first);
		maxT = max(maxT, e.second);
	}
	
	for (int time = minT; time < maxT; ++time)
	{
		int truckNum = 0;
		for (auto& range : timeRanges) if(isParking(range, time)) truckNum++;
		if (truckNum) totalCharge += (charge[truckNum - 1] * truckNum);
	}

	cout << totalCharge;
}

int A, B, C, a, b, cnt[104], ret;
void solution2()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; ++i)
	{
		cin >> a >> b;
		for (int j = a; j < b; ++j)
		{
			cnt[j]++;
		}
	}
	for (int i = 0; i < 100; ++i)
	{
		if (cnt[i] == 1) ret += A * 1;
		else if (cnt[i] == 2) ret += B * 2;
		else if (cnt[i] == 3) ret += C * 3;
	}
	cout << ret;
}