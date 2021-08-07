#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 참고 */
// https://www.acmicpc.net/board/view/66953

int counter(vector<long long> lan, long long length) // 주어진 랜선의 길이 length로 가지고 있는 랜선들을 잘랐을 때 나오는 랜선의 개수를 구하는 함수
{
    int cnt = 0;
    for (int i = 0; i < lan.size(); i++)
        cnt = cnt + (lan[i] / length);

    return cnt;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    int N;

    cin >> K >> N;

    vector<long long> lan(K); // 주어진 N 값의 범위를 충족시키기 위해 long long 타입을 선언하였다.
    for (int i = 0; i < K; i++)
        cin >> lan[i];

    long long low = 1;
    long long high = *max_element(lan.begin(), lan.end()); // 처음엔 제일 최소로 자를 수 있는 길이인 1과 주어진 랜선 중 가장 긴 랜선을 각각 low와 high로 설정
    int ans = 0;                                           // 나올 수 있는 랜선의 갯수를 저장할 변수

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        // 문제에서 랜선을 N개보다 더 많이 만드는 것 또한 N개를 만드는 것에 포함된다 하였으므로 N보다 크거나 같을 경우로 조건문을 설정 후
        // 최댓값을 구하듯이 값을 저장해가면서 이분탐색을 진행하고 만들 수 있는 최대 랜선의 길이를 구한다.
        if (counter(lan, mid) >= N)
        {
            low = mid + 1;
            if (ans < mid)
                ans = mid;
        }
        else if (counter(lan, mid) < N)
            high = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}