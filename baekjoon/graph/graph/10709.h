#pragma once
#include <iostream>
using namespace std;

int h, w;

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
				check = j;
			}
			else
			{
				if (check != -1) cout << j - check << " ";
				else cout << -1 << " ";
			}
		}
		cout << '\n';
	}
}
