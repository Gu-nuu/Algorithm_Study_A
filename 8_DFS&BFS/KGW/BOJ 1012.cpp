#include <iostream>
#include <string.h>

using namespace std;

int M, N, K;

int **farm;
int **isVisited;

int dir_row[4] = {1, 0, -1, 0};
int dir_col[4] = {0, 1, 0, -1}; // 현재 위치를 중심으로 상하좌우로 움직이기 위한 좌표값

void DFS(int row, int col);

void init();

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T > 0)
    {
        cin >> M >> N >> K; // M = col, N = row, K = baechu

        farm = new int *[N]; // 입력받은 밭의 크기만큼 2차원 배열을 동적할당
        for (int i = 0; i < N; i++)
        {
            farm[i] = new int[M];
            memset(farm[i], 0, sizeof(int) * M);
        }

        isVisited = new int *[N]; // 방문한 곳인지 확인하기 위한 2차원 배열. farm과 같은 크기로 동적할당
        for (int i = 0; i < N; i++)
        {
            isVisited[i] = new int[M];
            memset(isVisited[i], 0, sizeof(int) * M);
        }

        for (int i = 0; i < K; i++) // 배추가 심어져있는 곳을 입력받아 표시
        {
            int X, Y; // X = col, Y = row
            cin >> X >> Y;

            farm[Y][X] = 1;
        }

        int earthworm = 0; // 배추흰지렁이 마리 수

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (farm[i][j] == 1 && isVisited[i][j] == 0) // 만약 배추가 심어져있고 방문하지 않았던 곳이라면 배추흰지렁이를 풀고 주위 인접한 곳에 배추가 있는지를 DFS로 탐색
                {
                    earthworm++;
                    isVisited[i][j] = 1;
                    DFS(i, j);
                }
            }
        }

        cout << earthworm << "\n";

        T--;
    }

    init();

    return 0;
}

void DFS(int row, int col)
{
    for (int i = 0; i < 4; i++) // 현재 위치 {row, col}을 기준으로 상하좌우를 계산한다.
    {
        int next_row = row + dir_row[i];
        int next_col = col + dir_col[i];

        if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M) // 만약 밭을 넘어가게 된다면 해당 좌표는 무시
            continue;

        if (farm[next_row][next_col] == 1 && isVisited[next_row][next_col] == 0) // 만약 배추가 심어져있고 방문하지 않았던 곳이라면 해당 위치로 옮겨 DFS를 계속 진행
        {
            isVisited[next_row][next_col]++;
            DFS(next_row, next_col);
        }
    }
}

void init() // 2차원 배열 동적할당 해제 함수
{
    for (int i = 0; i < N; i++)
    {
        delete[] farm[i];
    }
    delete[] farm;

    for (int i = 0; i < N; i++)
    {
        delete[] isVisited[i];
    }
    delete[] isVisited;
}