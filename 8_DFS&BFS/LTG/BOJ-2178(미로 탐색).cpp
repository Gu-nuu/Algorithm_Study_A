#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int **maze, **visited, **dist;
int **distance;
int BFS();

int main()
{
	string input;
	cin >> N >> M;
	maze = new int*[N];
	visited = new int*[N];
	dist = new int*[N];
	for (int i = 0; i < N; i++) {
		maze[i] = new int[M];
		visited[i] = new int[M];
		dist[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			maze[i][j] = input[j] - '0';
		}
	}
	cout << BFS();
}

int BFS()
{
	queue<pair<int, int>> q;
	pair<int, int> visit;

	q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!q.empty()) {
		visit = q.front();
		if (visited[visit.first][visit.second] == 0) {
			visited[visit.first][visit.second] = 1;
			if (visit.first == N-1 && visit.second == M-1)
				return dist[N - 1][M - 1];
			q.pop();
			//위
			if (visit.first > 0 && maze[visit.first - 1][visit.second] == 1) {
				q.push({ visit.first - 1, visit.second });
				dist[visit.first - 1][visit.second] = dist[visit.first][visit.second]+1;
			}
			//오른쪽
			if (visit.second < M - 1 && maze[visit.first][visit.second + 1] == 1) {
				q.push({ visit.first, visit.second + 1 });
				dist[visit.first][visit.second+1] = dist[visit.first][visit.second] + 1;
			}
			//아래
			if (visit.first < N - 1 && maze[visit.first + 1][visit.second] == 1) {
				q.push({ visit.first + 1, visit.second });
				dist[visit.first+1][visit.second] = dist[visit.first][visit.second] + 1;
			}
			//왼쪽
			if (visit.second > 0 && maze[visit.first][visit.second - 1] == 1) {
				q.push({ visit.first, visit.second - 1 });
				dist[visit.first][visit.second-1] = dist[visit.first][visit.second] + 1;
			}
		}
		else
			q.pop();
	}
}