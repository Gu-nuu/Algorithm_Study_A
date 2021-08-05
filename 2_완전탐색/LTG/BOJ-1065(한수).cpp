#include <iostream>

using namespace std;

int main()
{
	int n, count;
	cin >> n;

	if (n < 111) {
		if (n < 99)
			count = n;
		else
			count = 99;
	}
	else
	{
		int first, second, num, diff = 0;
		count = 100;
		for (int i = 112; i <= n; i++) {
			first = i % 10;
			num = i / 10;
			second = num % 10;
			diff = second - first;

			while (num > 0) {
				first = num % 10;
				num = num / 10;
				second = num % 10;

				if (diff != second - first)
					break;
			}
			if (num == 0) {
				count++;
				//cout << i << "\n";
			}
		}
	}
	cout << count;
}