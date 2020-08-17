
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
	string answer = "";
	if (s.length() % 2 == 1)
		answer = s[s.length() / 2];
	else
		answer = s.substr(s.length() / 2 - 1, 2);
	return answer;
}

int main()
{
	cout << solution("abcd") << endl;
	return 0;
}
