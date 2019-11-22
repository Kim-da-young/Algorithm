// 프로그래머스 (전화번호 목록)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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