#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int cnt = 0;
	int SameNumber;
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