#include <iostream>
#include <queue>

using namespace std;

//priority_queue ���� ����� ���� compare ����ü
struct compare {
	//���� �� �Լ� bool operator()
	bool operator()(int x, int y) {
		if (abs(x) == abs(y))
			return x > y;
		return abs(x) > abs(y);
	}
};

int main()
{
	ios::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, input;
	priority_queue<int, vector<int>, compare> q; //compare ����ü ����� ���Ƿ� priority_queue�� ���� ����� ������

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