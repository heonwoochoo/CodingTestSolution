#pragma once
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int NUM_MAX = 104;
int n, m, y, x;
int visited[NUM_MAX][NUM_MAX], a[NUM_MAX][NUM_MAX];
int dy[] = { 0, -1, 1, 0 };
int dx[] = { 1, 0, 0, -1 };

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf_s("%1d", &a[i][j]);

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });
	while (q.size() != 0)
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	printf_s("%d",visited[n - 1][m - 1]);
}