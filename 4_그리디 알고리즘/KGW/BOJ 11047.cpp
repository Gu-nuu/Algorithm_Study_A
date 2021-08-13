#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<int> price(N); // 동전의 가치를 저장할 벡터

    for (int i = 0; i < N; i++)
        cin >> price[i];

    int temp = K;
    int ans = 0;
    for (int i = price.size() - 1; i >= 0; i--) // 최소한의 동전 개수를 사용해야 하기 때문에 가능한 큰 동전 가치부터 사용하기 위해 역순으로 진행하였다.
    {
        if (K < price[i]) // K원을 만드려고 하는데 그보다 큰 동전 가치가 있다면 필요가 없으므로 continue
            continue;

        if (temp == 0) // 동전으로 K원을 만든 경우 break
            break;

        ans += (temp / price[i]); // 필요한 동전의 갯수를 ans에 카운트
        temp %= price[i];         // 사용한 동전의 가치만큼 만드려고 한 K원에서 빼줌
    }

    cout << ans << "\n";

    return 0;
}