#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a[], int b[])
{
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int main()
{
	int n, **table;

	cin >> n;

	table = new int*[n];

	for (int i = 0; i < n; i++) {
		table[i] = new int[2];
		cin >> table[i][0] >> table[i][1];
	}

	sort(table, table + n, compare);
	
	for (int i = 0; i < n; i++) {
		cout << table[i][0] << " " << table[i][1] << "\n";
	}
}