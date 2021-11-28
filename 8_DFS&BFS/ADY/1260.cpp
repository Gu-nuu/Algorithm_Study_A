#include <iostream>
#include <stack>
#include <queue>
#include <vector> 
#include <algorithm>

using namespace std;

void DFS(vector<int>* graph, int S, bool* vlist){
	if(vlist[S]) return;
	else{
		vlist[S] = true;
		cout<<S<<' ';
		for(int i=0; i<graph[S].size(); i++){
			int temp = graph[S][i];
			if(!vlist[temp]){//아직 방문 안한 노드 
				DFS(graph, temp, vlist);
			}
		}
	}
}

void BFS(vector<int>* graph, int S, bool* vlist){
	queue<int> q;
	q.push(S);
	vlist[S] = true;
	
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout<<temp<<' ';
		for(int i=0; i<graph[temp].size(); i++){
			int cur = graph[temp][i];
			if(!vlist[cur]){
				q.push(cur);
				vlist[cur] = true;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, S, u, v;
	cin>>N>>M>>S;
	
	
	vector<int>* graph = new vector<int>[N+1];
	bool vlist[N+1];
	
	for(int i=0; i<M; i++){//그래프 정보 입력 및 저장 
		cin>>u>>v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1; i<=N; i++){//그래프 정렬 
		sort(graph[i].begin(), graph[i].end());
	}
	for(int i=0; i<N+1; i++){
		vlist[i] = false;
	} 
	
	DFS(graph, S, vlist);//DFS 실행 
	cout<<'\n';
	for(int i=0; i<N+1; i++){
		vlist[i] = false;
	}
	BFS(graph, S, vlist);//BFS 실행 
	
	return 0;
}
