#include <iostream>
#include <algorithm>

using namespace std;

int N;

//찾고자 하는 요소 중 첫번째 요소를 찾는 함수
int lower_bound(int *A, int target)
{
	int left = 0, right = N - 1, mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (target <= A[mid]) {
			right = mid;
		}
		else
			left = mid + 1;
	}
	return left;
}

//찾고자 하는 요소보다 큰 최소의 요소를 찾는 함수
int upper_bound(int *A, int target)
{
	int left = 0, right = N - 1, mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (target >= A[mid]) {
			left = mid + 1;
		}
		else
			right = mid;
	}
	if (A[left] == target)
		return left + 1;
	return left;
}

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, *B, i, num, *A;

	cin >> N;
	A = new int[N];
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	B = new int[M];
	for (i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	for (i = 0; i < M; i++) {
		cout << upper_bound(A, B[i]) - lower_bound(A, B[i]) << " ";
	}

	delete[] A, B;
}