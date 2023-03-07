#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <utility>
using namespace std;

int n, m, x, maxRes = INT_MIN;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

array<array<int, 9>, 9> arr;
array<array<int, 9>, 9> copyArr;
array<array<int, 9>, 9> check;
vector<pair<int,int>> vec;

void go(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 1 || ny > n || nx < 1 || nx > m || check[ny][nx] == 1 || copyArr[ny][nx] != 0) continue;
		else
		{
			check[ny][nx] = 1;
			copyArr[ny][nx] = 2;
			go(ny, nx);
		}
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> x;
			arr[i][j] = x;
			if (x == 0)
			{
				vec.emplace_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			for (int k = j + 1; k < vec.size(); ++k)
			{
				for (auto& e : check)
				{
					e.fill(0);
				}

				copyArr = arr;
				copyArr[vec[i].first][vec[i].second] = 1;
				copyArr[vec[j].first][vec[j].second] = 1;
				copyArr[vec[k].first][vec[k].second] = 1;

				for (int y = 1; y <= n; y++)
				{
					for (int x = 1; x <= m; x++)
					{
						if (copyArr[y][x] == 2 && check[y][x] == 0)
						{
							check[y][x] = 1;
							go(y, x);
						}
					}
				}
				int res = 0;
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
					{
						if (copyArr[i][j] == 0) res++;
					}
				}
				maxRes = max(res, maxRes);
			}
		}
	}
	cout << maxRes;
}
