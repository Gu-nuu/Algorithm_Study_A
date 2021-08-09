//메모리 증가, 시간 단축

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int N, *A;

int binary_search(int target) 
{
	int left = 0, right = N-1, mid = (left+right)/2;

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

	//A배열 입력 받기
	cin >> N;
	A = new int[N];

	//cin 반복 호출을 피하기 위해 한 줄로 입력받아 처리
	cin.ignore();
	getline(cin, line);
	stringstream nums(line);

	for (int i = 0; i < N; i++) {
		nums >> A[i];
	}

	//B배열 입력 받기
	cin >> M;
	B = new int[M];

	cin.ignore();
	getline(cin, line);
	stringstream nums2(line);

	for (int i = 0; i < M; i++) {
		nums2 >> B[i];
	}

	sort(A, A+N);
	for (int i = 0; i < M; i++) {
		cout << binary_search(B[i]) << "\n";
	}
}
