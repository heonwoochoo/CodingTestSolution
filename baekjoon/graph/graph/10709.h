#pragma once
#include <iostream>
#include <string>
#include <array>
using namespace std;

int h, w;
array<array<int, 101>, 101> arr;

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < h; ++i)
	{
		int check = -1;
		for (int j = 0; j < w; ++j)
		{
			char tmp;
			cin >> tmp;
			
			if (tmp == 'c')
			{
				cout << 0 <<" ";
				//arr[i][j] = 0;
				check = j;
			}
			else
			{
				if (check != -1)
				{
					cout << j - check << " ";
					arr[i][j] = j - check;
				}
				else
				{
					cout << -1 << " ";
					arr[i][j] = -1;
				}
			}
		}
		cout << '\n';
	}
}
