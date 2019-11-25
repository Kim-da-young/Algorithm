// ���α׷��ӽ� (ü����)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve);

int main()
{
	int i, num, lost_num, reserve_num;
	cout << "��ü �л��� �� : ";
	cin >> num;
	cout << "ü������ �Ҿ���� �л��� �� : ";
	cin >> lost_num;
	vector<int> lost(lost_num);
	for (i = 0; i < lost_num; i++)
	{
		cin >> lost[i];
	}
	cout << "���� ü������ �ִ� �л��� �� : ";
	cin >> reserve_num;
	vector<int> reserve(reserve_num);
	for (i = 0; i < reserve_num; i++)
	{
		cin >> reserve[i];
	}
	cout << "ü�� ������ ���� �� �ִ� �л��� �ִ� : " << solution(num, lost, reserve) << endl;
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