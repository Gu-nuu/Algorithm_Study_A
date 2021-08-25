#include <iostream>
#include <queue>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int K, N, M, pushNum, order, cur;
	queue<int> imp;
	priority_queue<int> q;
	cin>>K;
	
	for(int i=0; i<K; i++){
		order = 1;
		cin>>N>>M;
		for(int j=0; j<N; j++){
			cin>>pushNum;
			imp.push(pushNum);
			q.push(pushNum); 
		}
		
		while(!imp.empty()){
			if(q.top() == imp.front()){
				imp.pop();
				q.pop();
				if(M == 0){
					cout<<order<<'\n';
					break;
				}else{
					M--;
					order++;
				}
			}else if(q.top() > imp.front()){
				cur = imp.front();//맨 뒤 순서로 보내기 
				imp.push(cur);
				imp.pop();
				if(M == 0){
					M = imp.size() - 1; 
				}else{
					M--;
				}
			}
		}
		
		while(!imp.empty()) imp.pop();
		while(!q.empty()) q.pop();
	}
	
	return 0;
}
