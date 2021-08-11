#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int *lans, int K, int N, int length);

int main()
{
	int K, N, *lans;

	cin >> K >> N;
	lans = new int[K];

	for (int i = 0; i < K; i++){
		cin >> lans[i];
	}
	cout << binary_search(lans, K, N, *max_element(lans, lans + K));
}

int binary_search(int *lans, int K, int N, int max)
{
	long long start = 1, end = max, mid;
	int result, answer = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		result = 0;

		for (int i = 0; i < K; i++) {
			result += lans[i] / mid;
		}

		if (result >= N) {
			start = mid + 1;
			if (mid > answer)
				answer = mid;
		}
		else
			end = mid -1;
	}
	return answer;
}