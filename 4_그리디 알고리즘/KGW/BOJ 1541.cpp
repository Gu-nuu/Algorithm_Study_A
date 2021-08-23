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

    string str;
    cin >> str;

    vector<int> nums; // 숫자를 저장할 벡터

    bool check = false; // - 부호가 나타나는지 확인할 변수
    string temp = "";

    for (int i = 0; i < str.size(); i++) // 반복문을 한번 더 돌리지 않고 조건문의 순서를 바꿈
    {
        if (str[i] >= 48 && str[i] <= 57) // 숫자에 해당하는 문자면 string으로 우선 저장
            temp += str[i];

        if (str[i] == '-' || str[i] == '+' || i == str.size() - 1) // 부호가 나타나거나 문자열의 끝인 경우 숫자를 정수로 변환하여 벡터에 저장
        {
            if (check) // - 부호가 나타난 이후라면 - 부호 뒤부터 괄호가 씌워져있는 상태이므로 -를 붙여 저장
                nums.push_back(-stoi(temp));
            else
                nums.push_back(stoi(temp)); // - 부호가 나타나기 전이라면 정수 그대로 저장

            temp.clear();

            if (str[i] == '-') // - 부호가 나타나는 이후부터 괄호를 씌워주게 되면 최솟값을 만들어낼 수 있다
                check = true;
        }
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    cout << sum << "\n";

    return 0;
}