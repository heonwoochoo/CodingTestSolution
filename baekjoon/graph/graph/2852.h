#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, score1, score2, prev1, prev2, res1, res2;
bool prevDraw = true;
int minToSec(const string& st)
{
	return stoi(st.substr(0, 2))*60 + stoi(st.substr(3,2));
}

string secToMin(int second)
{
	string m = to_string(second / 60);
	if (second / 60 < 10) m = "0" + m;

	string s = to_string(second % 60);
	if (second % 60 < 10) s = "0" + s;

	return m + ":" + s;
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
		int timeSec = minToSec(time);

		team == 1 ? score1++ : score2++;
		
		if (score1 == score2)
		{
			if (team == 2)
			{
				res1 += timeSec - prev1;
			}
			else
			{
				res2 += timeSec - prev2;
			}
			prevDraw = true;
		}
		else if (score1 > score2)
		{
			if (prevDraw)
			{
				prev1 = timeSec;
				prevDraw = false;
			}
		}
		else
		{
			if (prevDraw)
			{
				prev2 = timeSec;
				prevDraw = false;
			}
		}
	}
	
	if (score1 > score2)
	{
		res1 += 2880 - prev1;
	}
	else if (score2 > score1)
	{
		res2 += 2880 - prev2;
	}

	cout << secToMin(res1) << '\n' << secToMin(res2);
}

