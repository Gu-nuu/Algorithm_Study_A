#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    priority_queue<int, vector<int>, less<int>> pq; // 최대 힙을 구현해야 하므로 우선순위 큐에서 내림차순으로 최댓값부터 pop될 수 있도록 하였다.

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0) // 만약 숫자가 0일 때 힙이 비워져 있다면 0을 출력, 비워져있지 않다면 힙에서 pop한 숫자를 출력
        {
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(num); // 0 이외의 숫자는 모두 push
    }

    return 0;
}