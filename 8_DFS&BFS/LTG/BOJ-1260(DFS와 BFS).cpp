#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool graph[1001][1001];
bool node_visited[1001];

void dfs(int start, int nodes);
void bfs(int start, int nodes);

int main()
{
	int N, M, V;
	int start, end;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		graph[start][end] = true;
		graph[end][start] = true;
	}

	dfs(V, N);
	cout << "\n";
	for (int i = 1; i <= N; i++)
		node_visited[i] = false;
	bfs(V, N);
}

void dfs(int start, int nodes)
{
	int visit;
	stack<int> stk;
	stk.push(start);

	while (!stk.empty()) {
		visit = stk.top();	//q 맨 앞에 있는 정점 방문
		if (node_visited[visit] == false) {
			node_visited[visit] = true;
			stk.pop();
			for (int i = nodes; i >= 1; i--) {
				if (graph[visit][i] == true)
					stk.push(i);
			}
			cout << visit << " ";
		}
		else
			stk.pop();
	}
}

void bfs(int start, int nodes)
{
	int visit;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		visit = q.front();	//q 맨 앞에 있는 정점 방문
		if (node_visited[visit] == false) {
			node_visited[visit] = true;
			for (int i = 1; i <= nodes; i++) {
				if (graph[visit][i] == true)
					q.push(i);
			}
			cout << visit << " ";
		}
		q.pop();
	}
}