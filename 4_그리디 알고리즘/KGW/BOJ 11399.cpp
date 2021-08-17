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

    vector<int> time(N);

    for (int i = 0; i < N; i++)
        cin >> time[i];

    sort(time.begin(), time.end()); // 가장 걸리는 시간이 적은 사람부터 일을 처리하면 모두 최소시간 안에 처리가 가능

    vector<int> sum; // 각 사람들이 걸리는 시간을 저장할 벡터

    for (int i = 0; i < time.size(); i++) // 2중 for문을 이용하여 각 사람들의 걸리는 시간을 누적합으로 저장하여 벡터에 저장
    {
        int temp_sum = 0;
        for (int j = 0; j <= i; j++)
            temp_sum += time[j];
        sum.push_back(temp_sum);
    }

    int ans = 0;
    for (int i = 0; i < sum.size(); i++) // 걸리는 시간을 모두 더해줌
        ans += sum[i];

    cout << ans << "\n";

    return 0;
}