#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(vector<int> priorities, int location);

int main()
{
	int i, num, location;
	cout << "문서 수 (num) : ";
	cin >> num;
	vector<int> priorities(num);
	for (i = 0; i < num; i++)
	{
		cin >> priorities[i];
	}
	cout << "내 문서 위치 (0 ~ num-1) : ";
	cin >> location;
	cout << "내 문서는 " << solution(priorities, location) << " 번째로 인쇄";
	return 0;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int cnt = 0;
	int SameNumber = 0;
	int i;
	while (true)
	{
		for (i = 1; i < priorities.size(); i++)
		{
			if (priorities[0] < priorities[i])
			{
				int tmp = priorities.front();
				priorities.push_back(tmp);
				priorities.erase(priorities.begin());
				if (location == 0)
					location = priorities.size() - 1;
				else
					location -= 1;

				break;
			}
			else if (priorities[0] == priorities[i])
			{
				SameNumber++;
			}
		}
		if (i == priorities.size() || SameNumber == priorities.size() - 1)
		{
			if (location == 0)
			{
				answer = ++cnt;
				break;
			}
			else
			{
				priorities.erase(priorities.begin());
				cnt++;
				location -= 1;
			}
		}
	}
	return answer;
}
