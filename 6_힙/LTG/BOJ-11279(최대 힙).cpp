#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N, input;
	priority_queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << q.top() << "\n";
			q.pop();
		}
		else
			q.push(input);
	}
}