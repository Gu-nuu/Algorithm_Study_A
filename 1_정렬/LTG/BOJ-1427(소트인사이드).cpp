#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
	return a > b;
}

int main()
{
	string number;

	cin >> number;

	sort(number.begin(), number.end(), compare);

	cout << number;
}