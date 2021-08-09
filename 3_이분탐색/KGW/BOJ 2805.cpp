#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 지정된 길이로 나무를 자르고 가져갈 수 있는 나무의 총 길이를 구하는 함수
// 나무의 길이에서 지정된 길이만큼 잘랐을 때 0 이상이어야 가져갈 수 있는 길이가 된다.
long long cutting(vector<long long> tree, long long cut)
{
    long long sum = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        if (tree[i] - cut > 0)
            sum = sum + (tree[i] - cut);
    }

    return sum;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<long long> tree(N);

    for (int i = 0; i < N; i++)
        cin >> tree[i];

    long long low = 1;
    long long high = *max_element(tree.begin(), tree.end());
    long long ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (cutting(tree, mid) >= K) // 1654번과 비슷하게 주어진 나무의 길이만큼 가져가기 위해서 설정할 절단기의 최댓값을 구하는 것이므로 값을 저장해가면서 이분탐색을 진행한다.
        {
            low = mid + 1;
            if (ans < mid)
                ans = mid;
        }
        else if (cutting(tree, mid) < K)
            high = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}