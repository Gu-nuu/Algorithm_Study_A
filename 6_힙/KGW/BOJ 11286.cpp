#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    // 우선순위를 결정하는 기준이 정수와 해당 정수의 절댓값 2개이므로 pair로 우선순위 힙을 구성하였으며,
    // 이때 절댓값이 가장 "작은" 순 -> 숫자가 "작은" 순으로 pop되어야 하므로 greater를 사용하였다.
    // 우선순위 큐 안에서 first인 절댓값이 작은 순으로 정렬이 일어나고 만약 같은 값이라면
    // second인 기본 정수가 작은 순으로 정렬이 일어나기 떄문에 문제 조건을 만족한다.
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top().second << "\n"; 
                pq.pop();
            }
        }
        else
            pq.push({abs(num), num}); // 우선적인 고려사항은 절댓값의 크기이므로 first 인자에 절댓값을 넣어준다.
    }

    return 0;
}