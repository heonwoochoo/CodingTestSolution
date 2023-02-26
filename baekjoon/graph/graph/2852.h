#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int score1 = 0;
int score2 = 0;
int curWin = 0;
int first1T = 0;
int second1T = 0;
int res1 = 0;
int res2 = 0;
bool draw = true;
int getSec(const string& st)
{
	string tmp{""};
	vector<int> time;
	for (auto& e : st)
	{
		if (e == ':') tmp = "";
		else tmp += e;
		if (tmp.size() == 2) time.emplace_back(stoi(tmp));
	}
	return time[0] * 60 + time[1];
}

void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int team;
		string time;
		cin >> team >> time;
		int timeSec = getSec(time);
		if (draw)
		{
			if (team == 1)
			{
				score1++;
				curWin = 1;
				first1T = timeSec;
			}
			else
			{
				score2++;
				curWin = 2;
				second1T = timeSec;
			}
			draw = false;
		}
		
		else
		{
			if (curWin == team && !draw) team == 1 ? score1++ : score2++;
			else
			{
				team == 1 ? score1++ : score2++;
				if (score1 > score2)
				{
					res2 += (timeSec - first1T);
					first1T = timeSec;
					curWin = 1;
				}
				else if (score1 < score2)
				{
					res1 += (timeSec - second1T);
					second1T = timeSec;
					curWin = 2;
				}
				else
				{
					// 비기고 있을 때
					draw = true;
					if (team == 1)
					{
						first1T = timeSec;
					}
					else
					{
						second1T = timeSec;
					}
				}
			}
		}
	}
	if (curWin == 1 && !draw)
	{
		res1 += 2880 - first1T;
	}
	else if (curWin == 2 && !draw)
	{
		res2 += 2880 - second1T;
	}
	
	cout << res1 << " " << res2;
	// 출력 : 첫번째, 두번째 팀이 이기고 있던 시간
}

