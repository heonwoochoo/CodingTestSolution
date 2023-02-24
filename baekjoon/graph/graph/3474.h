#pragma once
#include <iostream>

using namespace std;


int t, tmp;

int devidedNum(int num, int n)
{
	int res = 0;
	int m = n;
	while (num >= m)
	{
		res += int(num / m);
		m *= n;
	}
	return res;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> tmp;
		int two = devidedNum(tmp,2);
		int five = devidedNum(tmp, 5);
		cout << min(two, five) << '\n';
	}
}
