#pragma once
#include <iostream>
#include <array>
#include <vector>
using namespace std;

array<array<int, 101>, 101> arr; // 전체 리스트
array<array<int, 101>, 101> visited; // 방문한 곳 체크

int low, col, num, pre, hours, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0, -1,1 };



void DFS(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= low || nx >= col || visited[ny][nx] == 1) continue;
		if (arr[ny][nx] == 1)
		{
			visited[ny][nx] = 1;
			arr[ny][nx] = 0;
			num++;
			continue;
		}
		else if (arr[ny][nx] == 0)
		{
			visited[ny][nx] = 1;
			DFS(ny, nx);
		}
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (auto& ar : arr) ar.fill(0);
	for (auto& ar : visited) ar.fill(0);

	cin >> low >> col;
	for (int i = 0; i < low; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int tmp;
			cin >> tmp;
			
			if (tmp == 1)
			{
				arr[i][j] = tmp;
			}
		}
	}

	while (1)
	{
		visited[0][0] = 0;
		DFS(0, 0);
		if (num == 0) break;
		for (auto& ar : visited) ar.fill(0);
		pre = num;
		num = 0;
		hours++;
	}
	cout << hours << '\n';
	cout << pre << '\n';
}
