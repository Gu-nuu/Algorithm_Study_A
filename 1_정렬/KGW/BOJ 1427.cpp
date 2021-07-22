#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) // sort를 이용하여 정렬할 때 내림차순으로 정렬하도록 설정
{
    return a > b;
}

int main()
{
    // 입출력 시간을 줄이기 위함
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> box;
    int num;
    cin >> num;

    while (true) // 10으로 나눈 나머지를 이용하여 숫자를 자릿수대로 분리해준다.
    {
        box.push_back(num % 10);

        if (num / 10 == 0)
            break;
        else
            num /= 10;
    }

    sort(box.begin(), box.end(), compare);

    for (int i = 0; i < box.size(); i++)
        cout << box[i];

    return 0;
}