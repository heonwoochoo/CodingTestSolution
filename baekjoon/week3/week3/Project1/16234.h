#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, l, r, day, sum;
int arr[54][54];
int visited[54][54];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;

void DFS(int y, int x, vector<pair<int, int>>& v)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;

		int gap = abs(arr[ny][nx] - arr[y][x]);
		if (gap >= l && gap <= r)
		{
			visited[ny][nx] = 1;
			v.push_back({ny,nx});
			sum += arr[ny][nx];
			DFS(ny, nx, v);
		}
	}
}

void solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	while (1)
	{
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!visited[i][j])
				{
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });
					sum = arr[i][j];
					DFS(i, j, v);
					if (v.size() == 1) continue;
					for (pair<int, int> b : v)
					{
						arr[b.first][b.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}
		if (!flag) break;
		day++;
	}
	cout << day;
}