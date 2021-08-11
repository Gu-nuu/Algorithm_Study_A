#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> narr(N);
    for (int i = 0; i < N; i++)
        cin >> narr[i];

    int M;
    cin >> M;

    vector<int> marr(M);
    for (int i = 0; i < M; i++)
        cin >> marr[i];

    sort(narr.begin(), narr.end()); // 이진 탐색을 할 수들을 정렬한다.

    for (int i = 0; i < marr.size(); i++)
    {
        if (binary_search(narr.begin(), narr.end(), marr[i])) // algorithm 헤더에 있는 이진 탐색 함수로 찾고자 하는 수가 존재하면 true, 없다면 false를 return 한다.
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}