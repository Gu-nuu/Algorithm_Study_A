#include <iostream>

using namespace std;

int main()
{
	int test, N = 4, count;
	long long arr[101] = { 0, 1, 1, 1, 0, };
	cin >> test;

	for (int i = 0; i < test; i++) {
		count = N;
		cin >> N;
		
		while (arr[N] == 0) {
			arr[count] = arr[count - 3] + arr[count - 2];
			count++;
		}
		cout << arr[N] << "\n";
	}
}