#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    int start = 666; // 영화 제목은 666부터 시작
    while (true)
    {
        string temp = to_string(start); // "666"이 들어가있는지 확인하기 위해 string으로 변환

        // C++의 find 함수는 만약 특정 문자열을 찾았다면 시작하는 index를, 찾지 못했다면 string::pos를 반환한다.
        // 따라서 "666"을 찾을 때마다 카운트해줘야 하므로 찾은 경우를 != string::pos로 조건을 설정한다.
        if (temp.find("666") != string::npos)
            cnt++;

        if (cnt == N) // 만약 찾았다면 출력 후 종료
        {
            cout << start << "\n";
            break;
        }

        start++; // 숫자를 하나씩 늘려가며 탐색
    }

    return 0;
}