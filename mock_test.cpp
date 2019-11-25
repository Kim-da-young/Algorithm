// ���α׷��ӽ� (���ǰ��)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> answers);

int main()
{
	int i, num;
	cout << "���� �� : ";
	cin >> num;
	vector<int> answers(num);
	cout << "�� ���� ����" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> answers[i];
	}
	vector<int> answer = solution(answers);
	cout << "���� ���� ���� ��� : " << endl;
	for (i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> answer1 = { 1,2,3,4,5 };
	vector<int> answer2 = { 2,1,2,3,2,4,2,5 };
	vector<int> answer3 = { 3,3,1,1,2,2,4,4,5,5 };
	vector<int> cnt = { 0,0,0 };
	int i;
	for (i = 0; i < answers.size(); i++)
	{
		if (answers[i] == answer1[i % 5])
			cnt[0]++;
		if (answers[i] == answer2[i % 8])
			cnt[1]++;
		if (answers[i] == answer3[i % 10])
			cnt[2]++;
	}
	int m = *max_element(cnt.begin(), cnt.end());
	for (i = 0; i < 3; i++)
	{
		if (m == cnt[i])
			answer.push_back(i + 1);
	}
	return answer;
}