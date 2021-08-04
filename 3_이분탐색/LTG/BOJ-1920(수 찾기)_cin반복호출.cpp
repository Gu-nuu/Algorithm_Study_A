#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int N, *A;

int binary_search(int target)
{
	int left = 0, right = N-1, mid = (left + right) / 2;

	while (left <= right) {
		if (A[mid] == target)
			return 1;
		else if (A[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;

		mid = (left + right) / 2;
	}
	return 0;
}

int main()
{
	int M, *B;
	string line;

	//A�迭 �Է� �ޱ�
	cin >> N;
	A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//B�迭 �Է� �ޱ�
	cin >> M;
	B = new int[M];

	//cin �ݺ� ȣ��
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	for (int i = 0; i < M; i++) {
		cout << binary_search(B[i]) << "\n";
	}
}