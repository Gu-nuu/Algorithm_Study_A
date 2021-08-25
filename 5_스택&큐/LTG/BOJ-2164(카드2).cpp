#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, top;
	cin >> N;

	vector<int> queue;
	for (int i = 1; i <= N; i++)
		queue.push_back(i);

	top = 0;
	while (N > 1) {
		top += 1;
		N -= 1;
		if (N == 1)
			break;
		queue.push_back(queue[top]);
		top += 1;
	}
	cout << queue[top];
}