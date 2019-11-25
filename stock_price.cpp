// ���α׷��ӽ� (�ֽİ���)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> prices);

int main()
{
	int i, num;
	cout << "�ֽİ��� �� : ";
	cin >> num;
	vector<int> prices(num);
	cout << "�� ���� �ֽİ���" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> prices[i];
	}
	vector<int> answer = solution(prices);
	for (i = 0; i < num; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int check = 0;
	answer.assign(prices.size(), 0);
	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[i] > prices[j])
			{
				answer[i] = j - i;
				check = 1;
				break;
			}
		}
		if (check == 0)
			answer[i] = prices.size() - i - 1;
		else
			check = 0;
	}
	return answer;
}