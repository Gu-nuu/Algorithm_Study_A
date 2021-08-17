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
		//현재 도시에서 다음 도시까지 필요한 기름 가격 저장
		current = cities[i];
		total_cost += current * roads[i];
		//현재 도시보다 저렴한 도시 직전까지 거리 누적 후 한번에 주유
		for (j = 1; j < n-i-1; j++) {
			if (current <= cities[i + j])
				total_cost += current * roads[i + j];
			else
				break;
		}
		//한번에 누적 주유한 만큼 도시 건너뛰기
		i += j-1 ;
		
		//더 짧고 간단한 코드
		/*if (current > cities[i])
			current = cities[i];
		total_cost += current * roads[i];*/
	}
	cout << total_cost;
}