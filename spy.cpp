#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
int solution(vector<vector<string>> clothes);

int main()
{
	int i, num;
	cout << "의상의 수 : ";
	cin >> num;
	vector<vector<string>> clothes(num, vector<string>(2));
	cout << "의상의 이름 의상의 종류" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> clothes[i][0] >> clothes[i][1];
	}
	cout << "서로 다른 옷의 조합의 수 : " << solution(clothes) << endl;
	return 0;
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int i;
	map <string, int> ootd;
	for (i = 0; i < clothes.size(); i++)
	{
		ootd[clothes[i][1]]++;
	}
	map <string, int> ::iterator it;
	for (it = ootd.begin(); it != ootd.end(); it++)
	{
		answer *= ((it->second) + 1);
	}
	answer -= 1;
	return answer;
}