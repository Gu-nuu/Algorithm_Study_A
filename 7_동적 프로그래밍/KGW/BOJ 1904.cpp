#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001]; // 최대 입력값을 모두 받을 수 있도록 배열을 생성

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    arr[0] = 0;
    arr[1] = 1; // 타일을 만들 수 있는 갯수는 피보나치 수열과 똑같기 떄문에 동적 프로그래밍으로 피보나치 수열을 계산

    // 자연수 N이 주어질 때 구하고자 하는 타일의 갯수는 (N+1)번째 피보나치 수열이 된다. 이때 자료형의 범위를 벗어나지 않도록
    // 15746으로 나눈 나머지를 배열에 저장한다.
    for (int i = 2; i <= N + 1; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;

    cout << arr[N + 1] << endl;

    return 0;
}