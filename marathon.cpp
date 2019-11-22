// 프로그래머스 (완주하지 못한 선수)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int i = 0;
	int n = completion.size();
	for (i = 0; i < n; i++)
	{
		if (completion[i] != participant[i])
		{
			answer = participant[i];
			break;
		}
	}
	if (i == n)
		answer = participant[n];
	return answer;
}