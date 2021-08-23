#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, cost[1000], total = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	sort(cost, cost+N);

	int temp = 0;

	for (int i = 0; i < N; i++) {
		temp += cost[i];
		total += temp;
	}

	cout << total;
}