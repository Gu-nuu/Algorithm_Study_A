#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, height, weight, *rank;
	vector<pair<int, int>> input;

	cin >> n;
	rank = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> height >> weight;
		input.push_back({ height, weight });
		rank[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (input[i].first < input[j].first && input[i].second < input[j].second)
				rank[i]++;
		}
	}

	cout << rank[0];
	for (int i = 1; i < n; i++) {
		cout << " " << rank[i];
	}
}