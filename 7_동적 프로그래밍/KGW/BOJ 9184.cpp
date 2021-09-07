#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int w_arr[21][21][21]; // 메모이제이션 기법을 사용하기 위해 값을 저장할 배열을 선언한다.

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (w_arr[a][b][c] != 0) // 만약 배열 초기값 0이 아니라면 배열에 메모이제이션된 함수 결과 값이 들어가 있으므로 이를 사용
        return w_arr[a][b][c];

    if (a < b && b < c)
    {
        w_arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); // 배열에 값을 메모이제이션 후 배열 값을 반환
        return w_arr[a][b][c];
    }
    else
    {
        w_arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); // 배열에 값을 메모이제이션 후 배열 값을 반환
        return w_arr[a][b][c];
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(w_arr, 0, sizeof(w_arr)); // 초기 배열은 모두 0으로 값을 초기화

    while (true)
    {
        int num1, num2, num3;

        cin >> num1 >> num2 >> num3;

        if (num1 == -1 && num2 == -1 && num3 == -1)
            break;

        cout << "w(" << num1 << ", " << num2 << ", " << num3 << ") = " << w(num1, num2, num3) << "\n";
    }

    return 0;
}