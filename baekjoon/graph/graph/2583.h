#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int const NUM_MAX = 101;
int m, n, k, x_1, y_1, x_2, y_2, res, sum;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
array<array<int, NUM_MAX>, NUM_MAX> arr, visited;
vector<int> vec;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	sum++;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || arr[ny][nx] == 1 || visited[ny][nx] == 1) continue;
		else dfs(ny, nx);
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (auto& e : arr) e.fill(0);
	for (auto& e : visited) e.fill(0);

	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int y = y_1; y < y_2; ++y)
		{
			for (int x = x_1; x < x_2; ++x) arr[y][x] = 1;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == 0 && visited[i][j] == 0)
			{
				sum = 0;
				res++;
				dfs(i, j);
				vec.push_back(sum);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << res << '\n';
	for (auto& e : vec) cout << e << " ";
}
