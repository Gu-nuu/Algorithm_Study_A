#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	int *trees = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	long long mid, start = 0, end = *max_element(trees, trees + N) - 1;
	long long result = 0, max = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		result = 0;

		for (int i = 0; i < N; i++) {
			if (trees[i] > mid)
				result += (trees[i] - mid);
		}

		if (result >= M) {
			start = mid + 1;
			if (mid > max)
				max = mid;
		}
		else
			end = mid - 1;
	}
	cout << max;
}