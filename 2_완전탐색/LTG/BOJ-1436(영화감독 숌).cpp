#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, i, count = 0;
	string num;
	cin >> n;

	for (i = 666; count < n; i++) {
		num = to_string(i);
		if (num.find("666") != std::string::npos) {
			count++;
		}
	}
	cout << num;
}