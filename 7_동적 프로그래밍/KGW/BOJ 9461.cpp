#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long P[101]; // int로 설정하면 범위가 벗어나는 경우가 발생하여 타입을 long long으로 설정

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    memset(P, 0, sizeof(P)); // 초기 배열값을 모두 0으로 설정

    P[0] = 0;
    P[1] = 1;
    P[2] = 1; // 동적 프로그래밍을 이용하기 위해 초기값을 메모이제이션

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        for (int j = 2; j <= N; j++) // 1 1 1 '2' '2' 3 '4' 5 7 9... => ex) 2 + 2 = 4 (4번째 값 + 5번째 값 = 7번째 값)
        {
            P[j + 1] = P[j - 1] + P[j - 2]; // 파도반 수열의 점화식
        }

        cout << P[N] << "\n";
    }

    return 0;
}