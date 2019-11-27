// ���α׷��ӽ� (ž)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> heights);

int main()
{
	int i, num;
	cout << "ž�� ���� : ";
	cin >> num;
	vector<int> heights(num);
	cout << "�۽� ž�� ����" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> heights[i];
	}
	vector<int> answer = solution(heights);
	cout << "���� ž�� ��ġ" << endl;
	for (i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size());
	int i, j;
	for (i = heights.size() - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (heights[i] < heights[j])
			{
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}