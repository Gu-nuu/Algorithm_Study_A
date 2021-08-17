#include <iostream>

using namespace std;

int main()
{
	int N, K, *coins, i, result = 0;

	cin >> N >> K;
	coins = new int[N];

	for (i = 0; i < N; i++) {
		cin >> coins[i];
	}

	for (i = 0; i < N; i++) {
		if (K < coins[i])
			break;
	}

	for (int j = i - 1; K > 0; j--) {
		if (K >= coins[j]) {
			result += K / coins[j];
			K = K % coins[j];
		}
	}
	cout << result;
}