#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) // 정렬을 할 때, 나이를 기준으로 정렬하도록 compare 함수를 설정
{
    return a.first < b.first;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, string>> box;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        box.push_back({age, name});
    }

    // first 값이 같다면 기존의 sort 함수는 second 값을 보고 다시 정렬을 하지만, 나이가 같다면 가입을 한 순서대로 정렬을 진행해야 하므로
    // 값이 같은 값을 정렬해도 순서가 뒤바뀌지 않는 stable sort를 사용해야 한다.
    stable_sort(box.begin(), box.end(), compare);

    for (int i = 0; i < box.size(); i++)
        cout << box[i].first << " " << box[i].second << "\n";

    return 0;
}