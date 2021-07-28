#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> people; // pair를 이용해 사람들의 몸무게와 키를 한번에 입력 받아 저장
    for (int i = 0; i < N; i++)
    {
        int weight;
        int height;
        cin >> weight >> height;
        people.push_back({weight, height});
    }

    vector<int> grade;
    for (int i = 0; i < people.size(); i++) // 이중 for문을 이용해 완전 탐색을 하며 자신보다 덩치가 큰 사람을 찾아 등수를 산정. 이때 자기 자신은 제외
    {
        int cnt = 0;
        for (int j = 0; j < people.size(); j++)
        {
            if (i != j && people[i].first < people[j].first && people[i].second < people[j].second)
                cnt++;
        }
        grade.push_back(cnt + 1); // 자신보다 덩치가 큰 사람의 수 + 1이 등수가 됨
    }

    for (int i = 0; i < grade.size(); i++)
        cout << grade[i] << " ";

    return 0;
}