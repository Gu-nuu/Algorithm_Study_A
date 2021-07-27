#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	int n;
	string *table;
	
	cin >> n;

	table = new string[n];

	for (int i = 0; i < n; i++){
		cin >> table[i];
	}

	sort(table, table + n, comp);

	cout << table[0];
	for (int i = 1; i < n; i++) {
		if (table[i] == table[i - 1]) {
			continue;
		}
		cout << "\n" << table[i];
	}
}