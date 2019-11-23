// 프로그래머스 (기능개발)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds);

int main()
{
	int i, num;
	cout << "작업의 개수 : ";
	cin >> num;
	vector<int> progresses(num);
	vector<int> speeds(num);
	cout << "각 작업의 진행 정도" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> progresses[i];
	}
	cout << "각 작업의 진행 속도" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> speeds[i];
	}
	vector<int> answer;
	answer = solution(progresses, speeds);
	for (i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> distribution_date;
	int i, tmp = 0;
	for (i = 0; i < progresses.size(); i++)
	{
		tmp = 100 - progresses[i];
		if (tmp % speeds[i] == 0)
			distribution_date.push_back(tmp / speeds[i]);
		else
			distribution_date.push_back(tmp / speeds[i] + 1);
	}
	int max = 0;
	for (i = 1; i < progresses.size(); i++)
	{
		if (distribution_date[max] < distribution_date[i])
		{
			answer.push_back(i - max);
			max = i;
		}
	}
	answer.push_back(i - max);
	return answer;
}
