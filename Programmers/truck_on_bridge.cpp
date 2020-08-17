// ���α׷��ӽ� (�ٸ��� ������ Ʈ��)
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights);

int main()
{
	int i, num, bridge_length, weight;
	cout << "�ٸ� ���� : ";
	cin >> bridge_length;
	cout << "�ٸ��� �ߵ� �� �ִ� ���� : ";
	cin >> weight;
	cout << "Ʈ���� �� : ";
	cin >> num;
	cout << "�� Ʈ���� ����" << endl;
	vector<int> truck_weights(num);
	for (i = 0; i < num; i++)
	{
		cin >> truck_weights[i];
	}
	cout << "�� �ð� : " << solution(bridge_length, weight, truck_weights) << "��" << endl;
	return 0;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> current_weight;
	int sum = 0;
	int answer = 0;
	while(true)
	{
		if (truck_weights.size() == 0)
			break;
		int w = truck_weights[0];
		while (true)
		{
			if (current_weight.empty())
			{
				current_weight.push(w);
				answer++;
				sum += w;
				truck_weights.erase(truck_weights.begin());
				break;
			}
			else if (current_weight.size() == bridge_length)
			{
				sum -= current_weight.front();
				current_weight.pop();
			}
			else 
			{
				if (sum + w > weight) {
					current_weight.push(0);
					answer++;
				}
				else {
					current_weight.push(w);
					answer++;
					sum += w;
					truck_weights.erase(truck_weights.begin());
					break;
				}
			}
		}
	}
	answer += bridge_length;
	return answer;
}