#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 1001
using namespace std;

int N, M, V;

int adj[MAX][MAX];  // 인접행렬로 그래프를 구현
int isVisited[MAX]; // 방문한 노드인지를 확인할 배열

void DFS(int cur)
{
    isVisited[cur] = 1;

    cout << cur << " ";

    for (int i = 1; i <= N; i++)
    {
        if (isVisited[i] == 0 && adj[cur][i] == 1)
        {
            isVisited[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int cur)
{
    queue<int> q;

    isVisited[cur] = 1;
    q.push(cur);

    while (!q.empty())
    {
        int next = q.front();
        cout << next << " ";
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (isVisited[i] == 0 && adj[next][i] == 1)
            {
                isVisited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) // 양방향 그래프이므로 정점의 {i, j}와 {j, i}에 모두 연결이 되어있음을 표시
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }

    DFS(V);

    cout << "\n";

    fill_n(isVisited, MAX, 0); // DFS 탐색을 마치면 방문 노드를 다시 0으로 초기화

    BFS(V);

    return 0;
}