// 프로그래머스 (다리를 지나는 트럭)
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights);

int main()
{
	int i, num, bridge_length, weight;
	cout << "다리 길이 : ";
	cin >> bridge_length;
	cout << "다리가 견딜 수 있는 무게 : ";
	cin >> weight;
	cout << "트럭의 수 : ";
	cin >> num;
	cout << "각 트럭의 무게" << endl;
	vector<int> truck_weights(num);
	for (i = 0; i < num; i++)
	{
		cin >> truck_weights[i];
	}
	cout << "총 시간 : " << solution(bridge_length, weight, truck_weights) << "초" << endl;
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