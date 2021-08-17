#include <iostream>

using namespace std;

int main()
{
	int N, *cities, *roads;
	long long total_cost = 0;

	cin >> N;

	cities = new int[N];
	roads = new int[N - 1];

	for (int i = 0; i < N - 1; i++)
		cin >> roads[i];

	for (int i = 0; i < N; i++) 
		cin >> cities[i];

	int j;
	long long current = cities[0];

	for (int i = 0; i < N-1; i++) {
		//���� ���ÿ��� ���� ���ñ��� �ʿ��� �⸧ ���� ����
		current = cities[i];
		total_cost += current * roads[i];
		//���� ���ú��� ������ ���� �������� �Ÿ� ���� �� �ѹ��� ����
		for (j = 1; j < n-i-1; j++) {
			if (current <= cities[i + j])
				total_cost += current * roads[i + j];
			else
				break;
		}
		//�ѹ��� ���� ������ ��ŭ ���� �ǳʶٱ�
		i += j-1 ;
		
		//�� ª�� ������ �ڵ�
		/*if (current > cities[i])
			current = cities[i];
		total_cost += current * roads[i];*/
	}
	cout << total_cost;
}