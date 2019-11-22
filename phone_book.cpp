// 프로그래머스 (전화번호 목록)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool solution(vector<string> phone_book);

int main()
{
	vector<string> phone_book;
	int i, num;
	cout << "전화번호 수 : ";
	cin >> num;
	cout << "전화번호 목록" << endl;
	for (i = 0; i < num; i++)
	{
		string tmp;
		cin >> tmp;
		phone_book.push_back(tmp);
	}
	bool answer = solution(phone_book);
	cout << "한 번호가 다른 번호의 접두사인 경우가 ";
	if (answer)
		cout << "없음" << endl;
	else
		cout << "있음" << endl;
	return 0;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	int i;
	sort(phone_book.begin(), phone_book.end());
	for (i = 0; i < phone_book.size() - 1; i++)
	{
		if (phone_book[i + 1].substr(0, phone_book[i].length()) == phone_book[i])
		{
			answer = false;
			break;
		}
	}
	return answer;
}
