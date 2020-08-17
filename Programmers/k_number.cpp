// 프로그래머스 (K번째수)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands);

int main()
{
	int i, arr_num, com_num;
	cout << "배열 크기 : ";
	cin >> arr_num;
	vector<int> array(arr_num);
	cout << "배열 array" << endl;
	for (i = 0; i < arr_num; i++)
	{
		cin >> array[i];
	}
	cout << "명령 수 : " << endl;
	cin >> com_num;
	vector<vector<int>> commands(com_num, vector<int>(3));
	for (i = 0; i < com_num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> commands[i][j];
		}
	}
	vector<int> answer(com_num);
	answer = solution(array, commands);
	cout << "각 명령의 k번째 수" <<endl;
	for (i = 0; i < com_num; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tmp;
	for (int i = 0; i < commands.size(); i++)
	{
		tmp.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[commands[i][2] - 1]);
		tmp.clear();
	}
	return answer;
}
