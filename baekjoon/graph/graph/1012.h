#pragma once
#include <iostream>
#include <array>
using namespace std;

int const NUM_MAX = 51;
int t, m, n, k, x, y;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
array<array<int, NUM_MAX>, NUM_MAX> arr, visited;

void go(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] == 1 && visited[ny][nx] == 0) go(ny, nx);
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int res = 0;
		for (auto& e : arr) e.fill(0);
		for (auto& e : visited) e.fill(0);

		cin >> m >> n >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j] == 0 && arr[i][j] == 1)
				{
					res++;
					go(i, j);
				}
			}
		}
		cout << "Á¤´äÀº : " << res << endl;
	}
}
