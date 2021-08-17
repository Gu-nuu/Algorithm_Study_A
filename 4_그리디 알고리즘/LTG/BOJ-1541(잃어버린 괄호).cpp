#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string expression;
	cin >> expression;
	vector<int> nums;

	int i, num = 0, temp = 0, result = 0;

	for (i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			num = num * 10 + (expression[i] - '0');
		}
		else if (expression[i] == '+') {
			temp += num;
			num = 0;
		}
		if (expression[i] == '-' || i == expression.length()-1) {
			temp += num;
			nums.push_back(temp);
			temp = 0;
			num = 0;
		}
	}
	result = nums[0];
	for (i = 1; i < nums.size(); i++) {
		result -= nums[i];
	}
	cout << result;
}