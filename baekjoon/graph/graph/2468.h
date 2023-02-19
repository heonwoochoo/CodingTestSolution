#pragma once
#include <iostream>
#include <array>
using namespace std;

int n, tmp, h_max = 0, h_min = 100, r_max = 0;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
const int N_MAX = 101;
array<array<int, N_MAX>, N_MAX> arr, visited;

void dfs(int y, int x, int h)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || arr[ny][nx] == 0) continue;
		if (arr[ny][nx] > h) dfs(ny, nx, h);
		else arr[ny][nx] = 0;
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp;
			h_max = max(h_max, tmp);
			h_min = min(h_min, tmp);
			arr[i][j] = tmp;
		}
	}
	if (h_min == h_max)
	{
		cout << 1;
		return;
	}
	for (int i = h_min; i < h_max; ++i)
	{
		int res = 0;
		for (auto& e : visited) e.fill(0);
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (arr[j][k] <= i)
				{
					arr[j][k] = 0;
					visited[j][k] = 1;
				}
				if (arr[j][k] > i && visited[j][k] == 0)
				{
					res++;
					dfs(j, k, i);
				}
			}
		}
		r_max = max(r_max, res);
	}
	cout << r_max;
}
