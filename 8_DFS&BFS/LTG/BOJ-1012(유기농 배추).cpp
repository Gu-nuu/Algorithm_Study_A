#include <iostream>
#include <stack>

using namespace std;

int matrix[50][50];
int visit_check[50][50];
int T, M, N, K, X, Y;

int DFS();
void clear();

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		clear();
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			matrix[X][Y] = 1;
		}
		cout << DFS() << "\n";
	}
}

int DFS()
{
	int count = 0;
	stack<pair<int,int>> stk;
	pair<int, int> visit;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1 && visit_check[i][j] == 0) {
				stk.push({ i, j });
				while (!stk.empty()) {
					visit = stk.top();
					if (visit_check[visit.first][visit.second] == 0) {
						visit_check[visit.first][visit.second] = 1;
						stk.pop();
						//위
						if (visit.first > 0 && matrix[visit.first-1][visit.second] == 1 && visit_check[visit.first-1][visit.second] == 0)
							stk.push({ visit.first-1, visit.second});
						//오른쪽
						if (visit.second < N-1 && matrix[visit.first][visit.second+1] == 1 && visit_check[visit.first][visit.second+1] == 0)
							stk.push({ visit.first, visit.second+1 });
						//아래
						if (visit.first < M-1 && matrix[visit.first+1][visit.second] == 1 && visit_check[visit.first+1][visit.second] == 0)
							stk.push({ visit.first+1, visit.second});
						//왼쪽
						if (visit.second > 0 && matrix[visit.first][visit.second-1] == 1 && visit_check[visit.first][visit.second-1] == 0)
							stk.push({ visit.first, visit.second-1 });
					}
					else {
						stk.pop();
					}
				}
				count++;
			}
		}
	}
	return count;
}

void clear()
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			matrix[i][j] = 0;
			visit_check[i][j] = 0;
		}
	}
}