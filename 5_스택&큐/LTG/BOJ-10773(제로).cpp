#include <iostream>

using namespace std;

int main()
{
	int K, input = 0, result = 0, nums[100000], length = 0;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 0) {
			result -= nums[length-1];
			length--;
		}
		else {
			result += input;
			nums[length] = input;
			length++;
		}
	}
	cout << result;
}