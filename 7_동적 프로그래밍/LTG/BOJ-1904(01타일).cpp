#include <iostream>

using namespace std;

int main()
{
	int N, count = 3;
	long long arr[1000001] = { 0, 1, 2 };

	cin >> N;

	while (count <= N) {
		arr[count] = (arr[count - 2] + arr[count - 1]) % 15746;
		count++;
	}
	cout << arr[N];
}