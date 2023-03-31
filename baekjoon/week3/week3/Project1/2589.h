#pragma once
#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

int row, col, mx;
char arr[54][54];
int visited[54][54];
char tmp;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y,x));
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= row || nx < 0 || nx >= col) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
			mx = max(mx, visited[ny][nx]);
		}
	}
	return;
}

void solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (arr[i][j] == 'L') BFS(i, j);
		}
	}
	cout << mx - 1;
}