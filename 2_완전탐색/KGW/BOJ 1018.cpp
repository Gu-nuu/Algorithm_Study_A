#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    char **board = new char *[N]; // 입력 받은 체스판의 크기만큼 2차원 배열을 동적 할당
    for (int i = 0; i < N; i++)
        board[i] = new char[M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    // 올바른 체스판은 왼쪽 맨 위의 색깔이 W인 체스판과 B인 체스판 두 종류 뿐이므로 미리 올바른 모양의 2가지 체스판을 선언
    char white_board[8][8] = {{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

    char black_board[8][8] = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

    vector<int> count; // 다시 칠해야 하는 횟수를 담을 벡터

    // 브루트 포스 알고리즘을 이용하여 체스판을 비교
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int cnt_w = 0;
            int cnt_b = 0;
            for (int l = 0; l < 8; l++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (board[i + l][j + k] != white_board[l][k]) // 왼쪽 맨 위가 W인 체스판과 비교했을 때 다시 칠해야 할 경우 count
                        cnt_w++;

                    if (board[i + l][j + k] != black_board[l][k]) // 왼쪽 맨 위가 B인 체스판과 비교했을 때 다시 칠해야 할 경우 count
                        cnt_b++;
                }
            }
            count.push_back(cnt_w);
            count.push_back(cnt_b);
        }
    }

    int ans = *min_element(count.begin(), count.end()); // W 체스판과 B 체스판과 비교하여 다시 칠해야 하는 횟수 중에서 가장 최소인 값을 출력
    cout << ans << "\n";

    for (int i = 0; i < N; i++) // 동적 할당 해제
        delete[] board[i];
    delete[] board;

    return 0;
}