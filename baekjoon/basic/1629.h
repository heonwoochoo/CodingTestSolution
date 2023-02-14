#pragma once
#include <iostream>

using namespace std;

long long a;
long long b, c, res;

long long func(long long num, long long e)
{
	if (e == 1) return num % c;
	else if (e % 2) return func(num, e / 2) % c * func(num, e / 2 + 1) % c;
	else return func(num, e / 2) % c * func(num, e / 2) % c;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	res = func(a, b) % c;
	cout << res;
}
