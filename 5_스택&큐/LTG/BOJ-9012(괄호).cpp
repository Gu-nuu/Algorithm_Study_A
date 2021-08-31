#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, check;
	string input, result;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		check = 0;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '(')
				check++;
			else {
				check--;
				if (check < 0)
					break;
			}
		}
		if (check == 0)
			result += "YES\n";
		else
			result += "NO\n";
	}
	cout << result;
}