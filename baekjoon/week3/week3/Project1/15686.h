#pragma once
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m, tmp;

vector<pair<int, int>> home, chicken;
vector<vector<int>> chickenCombiList;

void combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		chickenCombiList.emplace_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); ++i)
	{
		v.emplace_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

// ���� ġŲ���� �ּ� �Ÿ�
int minDistance(vector<pair<int, int>> home, vector<int> chickenCombi)
{
	int ret = 0;
	for (auto& h : home)
	{
		int res = 987654321;
		for (auto& e : chickenCombi)
		{
			
			int dis = abs(h.first - chicken[e].first) + abs(h.second - chicken[e].second);
			res = min(res, dis);


		}
		cout << "�� (" << h.first << "," << h.second << ") �� ġŲ�� �Ÿ� :";
		ret += res;
		cout << res << '\n';
	}
	cout << "�Ÿ��� �� : " << ret << '\n';
	return ret;
}

void solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> tmp;
			if (tmp == 1) home.emplace_back(make_pair(i, j));
			else if (tmp == 2) chicken.emplace_back(make_pair(i, j));
		}
	}

	vector<int> vec;
	combi(-1, vec);
	int res = 987654321;
	for (auto& chickenCombi : chickenCombiList)
	{
		res = min(res,minDistance(home, chickenCombi));
		cout << '\n';
	}
	cout << "�ּ� �Ÿ���  : " << res << " �Դϴ�.\n";
}