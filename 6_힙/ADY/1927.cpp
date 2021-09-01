#include <iostream>
#include <queue>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, input;
	priority_queue<int, vector<int>, greater<int> > heap; //오름차순 
	
	cin>>N;
	
	for(int i=0; i<N; i++){
		cin>>input;		
		if(input == 0){//0일 경우 가장 작은 값 출력 
			if(heap.empty()){
				cout<<"0\n";
			}else{
				cout<<heap.top()<<'\n';
				heap.pop();//가장 작은 값 제거 
			}
		}else{
			heap.push(input);
		}
	}
	
	return 0;
}
