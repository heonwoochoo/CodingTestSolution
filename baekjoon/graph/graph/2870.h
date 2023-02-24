#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> vec;

string eraseZero(string& s)
{
	auto itr = find_if(s.begin(), s.end(), [](char s1) {
		if (s1 != '0') return true;
		else false;
		});
	if (itr != s.end())
	{
		s.erase(s.begin(), itr);
	}
	return s;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		string in = "", tmp = "";
		cin >> in;
		
		for (int i = 0; i < in.size(); ++i)
		{
			if (isdigit(in[i]))
			{
				tmp += in[i];
				if (i == in.size() - 1) vec.emplace_back(tmp);
			}
			else
			{
				if (tmp != "")
				{
					vec.emplace_back(tmp);
					tmp = "";
				}
			}
		}
	}
	for (auto& e : vec)
	{
		auto nonZeroItr = find_if(e.begin(), e.end(), [](char ch) {
			if (ch != '0') return true;
			else return false;
			});
		auto zeroItr = find(e.begin(), e.end(), '0');
		if (nonZeroItr < zeroItr) continue;
		else
		{
			if (nonZeroItr != e.end()) e.erase(e.begin(), nonZeroItr);
			else e = '0';
		};
	}

	sort(vec.begin(), vec.end(), [](const string& s1,const string& s2)
		{
			if (s1.size() < s2.size()) return true;
			else if (s1.size() > s2.size()) return false;
			else
			{
				for (int i = 0; i < s1.size(); ++i)
				{
					if (s1[i] < s2[i]) return true;
					else if (s1[i] == s2[i]) {
						if (i == s1.size() - 1) return false;
						continue;
					}
					else return false;
				}
			}
		});
	for (auto& e : vec) cout << e << '\n';
	
}
