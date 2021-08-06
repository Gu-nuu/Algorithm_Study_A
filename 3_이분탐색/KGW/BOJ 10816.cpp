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

    vector<int> sang(N);
    for (int i = 0; i < N; i++)
        cin >> sang[i];

    int M;
    cin >> M;

    vector<int> card(M);
    for (int i = 0; i < M; i++)
        cin >> card[i];

    sort(sang.begin(), sang.end());

    vector<int> count;

    // lower_bound()는 이진 탐색을 기반으로 특정 원소 x에 대해 x 이상의 원소 index를 반환하는 함수이며, upper_bound()는 lower_bound()와 비슷하지만
    // 특정 원소 x에 대해 x를 초과하는 원소 index를 반환하는 함수이다. 따라서 (upper_bound에서 구한 index 값) - (lower_bound에서 구한 index 값)을 해주면
    // 특정 원소 x의 갯수를 구할 수 있다.
    // ex) {1, 2, 2, 2, 3, 4} : 2를 찾고자 할 경우
    // upper_bound = index 값 4를 반환 => 2를 초과하여 3의 위치 index를 반환
    // lower_bound = index 값 1을 반환 => 2가 시작하는 위치 index를 반환
    for (int i = 0; i < card.size(); i++)
    {
        if (binary_search(sang.begin(), sang.end(), card[i]))
            count.push_back((upper_bound(sang.begin(), sang.end(), card[i]) - sang.begin()) - (lower_bound(sang.begin(), sang.end(), card[i]) - sang.begin()));
        else
            count.push_back(0);
    }

    for (int i = 0; i < count.size(); i++)
        cout << count[i] << " ";

    return 0;
}