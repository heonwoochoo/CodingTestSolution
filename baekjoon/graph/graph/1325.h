#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m, a, b;
vector<int> node[10004];
int check[10004];
int dp[10004];

int DFS(int Root)
{
	check[Root] = 1;
	int ret = 1;

	for (auto e : node[Root])
	{
		if (check[e] == 1) continue;
		
		ret += DFS(e);
	}
	
	return ret;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		// a가 b를 신뢰한다
		node[b].emplace_back(a);
	}

	vector<int> res;
	int maxNum = -1;
	
	for (int i = 1; i <= n; ++i)
	{
		memset(check, 0, sizeof(check));
		dp[i] = DFS(i);
		maxNum = max(maxNum, dp[i]);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] == maxNum)
		{
			cout << i << " ";
		}
	}
}
