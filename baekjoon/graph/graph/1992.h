#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NUM_MAX = 65;
int n;
vector<vector<int>> vec;
string res;


vector<vector<int>> devideVec(vector<vector<int>> vec, int s1, int e1, int s2, int e2)
{
	vector<vector<int>> vec_tmp;
	for (int i = s1; i < e1; ++i)
	{
		vector<int> vec_tmp2;
		for (int j = s2; j < e2; ++j)
		{
			vec_tmp2.push_back(vec[i][j]);
		}
		vec_tmp.push_back(vec_tmp2);
	}
	return vec_tmp;
}


int IsNeedQuad(vector<vector<int>> vec)
{
	int flag = vec[0][0];

	for (auto& e : vec)
		for (auto& v : e) if (flag != v) return 2;

	return flag;
}

string Quad(vector<vector<int>> vec)
{
	int tmp = IsNeedQuad(vec);
	if (tmp == 0)
	{
		return "0";
	}
	else if (tmp == 1)
	{
		return "1";
	}
	else
	{
		string str_tmp = "(";
		
		str_tmp += Quad(devideVec(vec, 0, int(vec.size() / 2), 0, int(vec.size() / 2)));
		str_tmp += Quad(devideVec(vec, 0, int(vec.size() / 2), int(vec.size() / 2), int(vec.size())));
		str_tmp += Quad(devideVec(vec, int(vec.size() / 2), int(vec.size()), 0, int(vec.size() / 2)));
		str_tmp += Quad(devideVec(vec, int(vec.size() / 2), int(vec.size()), int(vec.size() / 2), int(vec.size())));

		str_tmp += ")";
		return str_tmp;
	}
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		vector<int> vec_tmp;
		for (int j = 0; j < n; ++j)
		{
			int tmp;
			scanf_s("%1d", &tmp);
			vec_tmp.push_back(tmp);
		}
		vec.push_back(vec_tmp);
	}
	
	cout << Quad(vec);
}
