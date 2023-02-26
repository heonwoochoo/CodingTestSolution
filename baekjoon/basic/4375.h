#pragma once
#include <iostream>

using namespace std;

int n;
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n && n != EOF)
	{
		int cnt = 1, ret = 1;
		while (1)
		{
			if (cnt % n == 0)
			{
				cout << ret << '\n';
				break;
			}
			else
			{
				cnt = (cnt * 10) % n + 1;
				ret++;
			}
		}
	}
}
