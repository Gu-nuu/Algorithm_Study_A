#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int BFS(vector<vector<int>> maze, int N, int M)
{
    vector<vector<int>> check(N, vector<int>(M, 0)); // 미로를 이동할 때 필요한 걸음 수를 저장할 2차원 벡터. 미로 벡터와 마찬가지로 N * M의 벡터에 모두 0으로 초기화한 상태

    queue<pair<int, int>> q; // BFS를 구현하기 위한 큐. 2차원 미로이므로 행렬 값을 모두 저장하기 위해 pair 선언

    vector<int> dir_row = {1, 0, -1, 0};
    vector<int> dir_col = {0, 1, 0, -1}; // 현 위치를 중심으로 상하좌우로 움직이기 위해 사용할 변수.

    int cur_row = 0;
    int cur_col = 0;

    check[cur_row][cur_col] = 1;
    q.push({cur_row, cur_col});

    while (!q.empty())
    {
        cur_row = q.front().first;
        cur_col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) // 현 위치에서 상하좌우의 좌표를 계산 후 조건에 따라 다음 칸으로 전진한다.
        {
            int next_row = cur_row + dir_row[i];
            int next_col = cur_col + dir_col[i]; // 움직일 다음 칸의 좌표를 계산

            // 만약 다음에 움직일 칸의 좌표가 미로를 넘어가거나 미로에서 움직일 수 없는 칸인 0이거나 이미 방문했던 곳인 경우 continue로 무시하고 넘어감
            if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M || maze[next_row][next_col] == 0 || check[next_row][next_col] != 0)
                continue;
            else // 만약 다음에 움직일 수 있는 칸의 조건을 만족한다면 이전 좌표 + 1로 움직인 칸을 누적하여 더한 후 큐에 해당 좌표를 다시 push
            {
                check[next_row][next_col] = check[cur_row][cur_col] + 1;
                q.push({next_row, next_col});
            }
        }
    }

    return check[N - 1][M - 1];
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M, 0)); // 미로의 정보를 저장할 2차원 벡터. N * M의 2차원 벡터를 0으로 모두 초기화한 상태

    for (int i = 0; i < maze.size(); i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < maze[i].size(); j++) // 한 줄씩 string으로 입력받은 후 하나씩 분리하여 다시 int로 변환 후 저장
            maze[i][j] = line[j] - '0';
    }

    cout << BFS(maze, N, M) << "\n";

    return 0;
}