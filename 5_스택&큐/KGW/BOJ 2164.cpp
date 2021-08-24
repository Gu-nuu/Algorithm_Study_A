#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> q; // 가장 먼저 들어간 카드를 가장 위에 있는 카드라고 생각했을 때 큐로 문제 해결이 가능

    for (int i = 1; i <= N; i++) // 1부터 N까지의 카드를 큐에 집어넣음
        q.push(i);

    while (q.size() != 1) // 큐에 카드가 1장이 남을 때까지 반복문 수행
    {
        q.pop(); // 맨 위에 카드를 버림

        q.push(q.front()); // 카드를 버린 후 가장 위의 카드를 빼서 다시 카드의 맨 아래로 옮김
        q.pop();
    }

    cout << q.front() << "\n";

    return 0;
}