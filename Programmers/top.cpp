// 프로그래머스 (탑)
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> heights);

int main()
{
	int i, num;
	cout << "탑의 개수 : ";
	cin >> num;
	vector<int> heights(num);
	cout << "송신 탑의 높이" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> heights[i];
	}
	vector<int> answer = solution(heights);
	cout << "수신 탑의 위치" << endl;
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