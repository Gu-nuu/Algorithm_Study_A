#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    stack<int> book; // 장부

    for (int i = 0; i < K; i++)
    {
        int num;
        cin >> num;

        if (num == 0) // 0일 경우 가장 최근의 수를 지워야 하므로 stack으로 장부를 구현하여 가장 최근에 들어온 수를 pop한다.
            book.pop();
        else
            book.push(num); // 0이 아니라면 수를 장부에 push한다.
    }

    int sum = 0;
    while (!book.empty())
    {
        sum += book.top();
        book.pop();
    }

    cout << sum << "\n";

    return 0;
}