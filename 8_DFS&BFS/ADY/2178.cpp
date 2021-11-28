#include <iostream>
#include <queue>

using namespace std;

int N,M;
int** maze;
bool** vlist;
int direct[4][2] = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};//탐색방향(상하좌우) 

void BFS(){
	queue<pair<int, int> > q;
	pair <int, int> cur;
	int next_x, next_y;
	
	q.push(make_pair(0,0));//(0,0)부터 시작 
	vlist[0][0] = true;
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			next_x = cur.first + direct[i][0];
			next_y = cur.second + direct[i][1];
			if(next_x >= 0 && next_x <N && next_y >= 0 && next_y < M){
				if(maze[next_x][next_y] != 0 && vlist[next_x][next_y] == false){
					q.push(make_pair(next_x, next_y));
					vlist[next_x][next_y] = true;
					maze[next_x][next_y] = maze[cur.first][cur.second] + 1;
					//미로에 그 칸까지의 최소칸수를 입력하며 탐색 
				}
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	char input;
	
	cin>>N>>M;
	maze = new int*[N];
	vlist = new bool*[N];
	for(int i=0; i<N; i++){
		maze[i] = new int[M];
		vlist[i] = new bool[M];
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>input;
			maze[i][j] = input - '0';
			vlist[i][j] = false;
		}
	}
	
	BFS();
	cout<<maze[N-1][M-1];
	
	return 0;
}
