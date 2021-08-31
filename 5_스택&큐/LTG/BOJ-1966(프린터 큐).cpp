#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int test, N, M, order[100], top, result;
	vector<int> q;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> N >> M;
		top = 0;
		result = 0;
		for (int j = 0; j < N; j++) {
			cin >> order[j];
			q.push_back(order[j]);
		}
		sort(order, order + N);
		while (1) {
			if (q[top] == order[N - 1]) {
				result++;
				if (top == M)
					break;
				top++;
				N--;
			}
			else {
				q.push_back(q[top]);
				if (top == M)
					M += N;
				top++;
			}
		}
		cout << result << "\n";
		q.clear();
	}
}