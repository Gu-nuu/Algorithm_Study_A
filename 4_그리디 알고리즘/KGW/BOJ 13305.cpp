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

    // input 값의 범위가 계산할 때 int형의 범위를 넘어설 수 있기 때문에 long long으로 선언
    vector<long long> roadLength(N - 1);
    vector<long long> oilPrice(N);

    for (int i = 0; i < N - 1; i++)
        cin >> roadLength[i];

    for (int i = 0; i < N; i++)
        cin >> oilPrice[i];

    long long cost = 0;
    long long min = oilPrice[0];

    // 도시를 왼쪽에서부터 탐색하면서 적은 기름값을 계속 갱신하고 만약 다음 도시의 기름 값이 더 비싸다면 이전 도시의 기름 값으로 거리 비용을 계산하도록 한다.
    for (int i = 0; i < N - 1; i++)
    {
        if (oilPrice[i] < min)
            min = oilPrice[i];

        cost += (roadLength[i] * min);
    }

    cout << cost << "\n";

    return 0;
}