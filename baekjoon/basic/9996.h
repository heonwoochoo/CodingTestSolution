#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution() {
	int n;
	string pattern;
	vector<string> files;
	cin >> n;
	cin.ignore();
	getline(cin,pattern);

	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		files.push_back(tmp);
	}

	int index = pattern.find('*');
	string pre = pattern.substr(0, index);
	string suf = pattern.substr(index + 1);

	for (auto& file : files)
	{
		if (file.size() < pattern.size() - 2) cout << "NE" << endl;
		else if (file.substr(0, pre.size()) == pre && file.substr(file.size() - suf.size()) == suf) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
}
