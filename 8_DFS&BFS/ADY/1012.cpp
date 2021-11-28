#include <iostream>

using namespace std;

bool** farm;
bool** vlist;
int N, M;
int direct[4][2] = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};//탐색방향(상하좌우) 

void DFS(int x, int y){
	int next_x, next_y;
	
	vlist[x][y] = true;
	//상하좌우로 탐색 
	for(int i=0; i<4; i++){
		next_x = x + direct[i][0];
		next_y = y + direct[i][1];
		if(next_x >= 0 && next_x <N && next_y >= 0 && next_y < M){
			if(farm[next_x][next_y] == true && vlist[next_x][next_y] == false){
				DFS(next_x, next_y);
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T, K, x, y, count;
	
	cin>>T; 
	
	for(int i=0; i<T; i++){
		count = 0;
		cin>>N>>M>>K;
		farm = new bool*[N];
		vlist = new bool*[N];
		for(int j=0; j<N; j++){
			farm[j] = new bool[M];
			vlist[j] = new bool[M];
		}
		for(int a=0; a<N; a++){
			for(int b=0; b<M; b++){
				farm[a][b] = false;
				vlist[a][b] = false;
			}
		}
		
		
		for(int j=0; j<K; j++){//배추 좌표 입력 
			cin>>x>>y;
			farm[x][y] = true;
		}
		
		
		for(int a=0; a<N; a++){
			for(int b=0; b<M; b++){
				if(farm[a][b] == true && vlist[a][b] == false){
					DFS(a, b);
					count++;
				}
			}
		}
		
		cout<<count<<'\n';
		
		/*
		
		for(int j=0; j<N; j++){
			delete[] farm[j];
			delete[] vlist[j];
		}
		delete[] farm;
		delete[] vlist;
		
		*/
	}
	
	return 0;
}
