<<<<<<< HEAD
// ���α׷��ӽ� (�������� ���� ����)
#include <string>
#include <vector>
#include <algorithm>
=======
// 프로그래머스 (완주하지 못한 선수)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
>>>>>>> 17b2a507bdd3a9c6c63792ba865dd9854fe8f0ed

using namespace std;
string solution(vector<string> p, vector<string> c);

<<<<<<< HEAD
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
=======
int main()
{
	vector <string> participant;
	vector <string> completion;
	int i, num;
	string tmp;
	cout << "마라톤 참가자 인원 : ";
	cin >> num;
	cout << "마라톤 참가자 명단" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> tmp;
		participant.push_back(tmp);
	}
	cout << "마라톤 완주자 명단" << endl;
	for (i = 0; i < num - 1; i++)
	{
		cin >> tmp;
		completion.push_back(tmp);
	}
	cout << "완주하지 못한 선수 : " << solution(participant, completion) << endl;;
	return 0;
}

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
>>>>>>> 17b2a507bdd3a9c6c63792ba865dd9854fe8f0ed
