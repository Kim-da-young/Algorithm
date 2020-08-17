// 프로그래머스 (체육복)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve);

int main()
{
	int i, num, lost_num, reserve_num;
	cout << "전체 학생의 수 : ";
	cin >> num;
	cout << "체육복을 잃어버린 학생의 수 : ";
	cin >> lost_num;
	vector<int> lost(lost_num);
	for (i = 0; i < lost_num; i++)
	{
		cin >> lost[i];
	}
	cout << "여분 체육복이 있는 학생의 수 : ";
	cin >> reserve_num;
	vector<int> reserve(reserve_num);
	for (i = 0; i < reserve_num; i++)
	{
		cin >> reserve[i];
	}
	cout << "체육 수업을 들을 수 있는 학생의 최댓값 : " << solution(num, lost, reserve) << endl;
	return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int i = 0, j = 0;
	for (i = 0; i < lost.size(); i++)
	{
		for (j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				--i;
			}
		}
	}
	for (i = 0; i < reserve.size(); i++)
	{
		for (j = 0; j < lost.size(); j++)
		{
			if (reserve[i] - lost[j] == 1 || reserve[i] - lost[j] == -1)
			{
				lost.erase(lost.begin() + j);
				reserve.erase(reserve.begin() + i);
				--i;
				break;
			}
		}
	}
	answer = n - lost.size();
	return answer;
}