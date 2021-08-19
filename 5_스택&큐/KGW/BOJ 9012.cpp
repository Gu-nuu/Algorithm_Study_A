#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        stack<int> check; // '('가 나오면 특정 값을 push하고 ')'가 나오면 stack에서 pop하여 올바른 괄호 한 쌍을 이루고 있는지 확인하기 위해 stack을 사용
        bool flag = true; // 괄호 문자열이 VPS인지 아닌지를 판별하는 변수

        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(') // '('가 나오면 특정 값을 push
                check.push(1);
            else if (str[j] == ')') // ')'가 나오면 스택이 비어있는지 아닌지를 우선 판단한다.
            {
                if (check.empty()) // 만약 스택이 비어있다면 해당 괄호는 나오면 안되므로 VPS를 만족하지 않기 떄문에 flag를 false로 바꿔준 후 반복문을 종료한다.
                {
                    flag = false;
                    break;
                }
                else
                    check.pop(); // 스택이 비어있지 않다면 스택에서 특정 값을 pop한다.
            }
        }

        if (!check.empty() || flag == false) // VPS를 만족하지 못할 경우는 모든 과정이 끝났지만 스택이 비어있지 않거나 스택이 이미 비었는데 ')'가 나타날 경우로 총 2가지이다.
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}