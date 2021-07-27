#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)        // 길이가 짧은 순으로 정렬하되, 길이가 같다면 사전 순으로 정렬하도록 compare 함수를 설정
{
    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> words;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());       // 문제에 주어진 조건으로 정렬 후 같은 단어들의 중복을 제거

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << "\n";

    return 0;
}