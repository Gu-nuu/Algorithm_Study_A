#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        queue<pair<int, int>> printer;                     // 프린터기
        priority_queue<int, vector<int>, less<int>> order; // 문서의 중요도를 가장 높은 것부터 출력하기 위한 우선순위 큐

        int number;
        int quest;
        cin >> number >> quest; // 문서의 갯수와 궁금한 문서 번호를 입력

        for (int j = 0; j < number; j++)
        {
            int weight;
            cin >> weight;

            printer.push({j, weight}); // 프린터기에 문서의 번호와 문서의 중요도 저장
            order.push(weight);        // 우선순위 큐에 중요도 저장
        }

        int cnt = 0;
        while (true)
        {
            int temp_doc = printer.front().first;
            int temp_importance = printer.front().second;

            int temp_order = order.top(); // 우선순위 큐에서는 중요도가 가장 큰 것부터 pop됨

            printer.pop();

            if (temp_importance == temp_order) // 중요도가 가장 높은 문서일 경우
            {
                order.pop();
                cnt++; // 문서를 프린터기 출력 목록에서 지워주고 궁금한 문서의 출력 순서를 증가시켜줌

                if (temp_doc == quest) // 출력 순서가 궁금했던 문서일 경우
                {
                    cout << cnt << "\n"; // 순서 출력 후 반복문 break
                    break;
                }
            }
            else
                printer.push({temp_doc, temp_importance}); // 중요도가 가장 높은 문서가 아닐 경우 아직 순서가 아니므로 다시 프린터기에 push
        }
    }

    return 0;
}