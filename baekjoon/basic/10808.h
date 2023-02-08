#pragma once
#include <iostream>
#include <string>
using namespace std;

void solution() {
	string s;
	cin >> s;
	int result['z' - 'a' + 1] = {0};

	for (auto& e : s) result[e - 'a']++;

	for (auto& e : result) cout << e << " ";
}