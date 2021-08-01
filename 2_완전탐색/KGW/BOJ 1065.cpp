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

    int cnt = 0;
    bool flag = true;
    // 문제에서는 정수의 각 자리가 등차수열을 이루어야 하며 등차수열은 연속된 두 개의 수의 치이가 일정한 수열이라고 했으므로
    // 1 ~ 99까지의 모든 수는 무조건 한수가 된다.

    if (N <= 99) // 주어진 수가 99 이하일 경우 주어진 N 값이 바로 한수의 갯수가 된다.
    {
        cnt = N;
        flag = false;
    }

    if (flag == true) // 주어진 수가 100 이상일 경우 한수인지 아닌지에 대한 판단이 필요하다.
    {
        for (int i = 1; i <= N; i++)
        {
            if (i <= 99) // 99 이하의 수는 모두 한수이므로 자릿수 계산을 할 필요가 없다.
            {
                cnt++;
                continue;
            }

            int tmp1 = i / 100 % 10; // 셋째 자리 수
            int tmp2 = i / 10 % 10;  // 둘째 자리 수
            int tmp3 = i % 10;       // 첫째 자리 수

            if (tmp2 - tmp1 == tmp3 - tmp2 && i != 1000) // 각 자리의 차이를 구해 일정하다면 count. 1000까지의 숫자가 주어지는데 1000은 한수가 될 수 없다.
                cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}