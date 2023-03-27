// Ʈ��
// https://www.acmicpc.net/problem/1068
#pragma once
#include <iostream>
#include <vector>
using namespace std;

int n; // Ʈ���� ����
vector<int> node[51];
int r; // ���� ��� ��ȣ
int tmp; // �ӽ� ���� ����
int root;

int DFS(int root)
{
	int ret = 0;
	int child = 0;
	for (auto e : node[root])
	{
		if (e == r) continue;
		ret += DFS(e);
		child++;
	}
	if (child == 0) return 1;
	else return ret;
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (tmp == -1) root = i;
		else node[tmp].emplace_back(i);
	}
	cin >> r;

	if (r == root)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << DFS(root) << '\n';
	}
}
