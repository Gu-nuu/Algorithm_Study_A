#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct item {
	int age;
	int order;
	string name;
};

bool comp(item a, item b) {
	if (a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}

int main()
{
	int n;
	cin >> n;

	item *arr = new item[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}

	sort(arr, arr + n, comp);

	cout << arr[0].age << " " << arr[0].name;
	for (int i = 1; i < n; i++) {
		cout << "\n" << arr[i].age << " " << arr[i].name;
	}
}