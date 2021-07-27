#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cnt;
    cin >> cnt;

    vector<pair<int, int>> point;

    for (int i = 0; i < cnt; i++)
    {
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }

    sort(point.begin(), point.end());

    for (int i = 0; i < point.size(); i++)
        cout << point[i].first << " " << point[i].second << "\n";       // 시간 초과의 문제로 인해 가급적이면 endl보다는 "\n"을 쓰자!

    return 0;
}