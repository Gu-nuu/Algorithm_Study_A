#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int> > heap_p;//+값 저장 
	priority_queue<int, vector<int>, less<int> > heap_m;//-값 저장
		
	int N, input;
	
	cin>>N;
	
	for(int i=0; i<N; i++){
		cin>>input;
		if(input == 0){
			if(heap_p.empty() && heap_m.empty()){
				cout<<"0\n";
			}else if(heap_p.empty()){//음수만 남음 
				cout<<heap_m.top()<<'\n';
				heap_m.pop();
			}else if(heap_m.empty()){//양수만 남음 
				cout<<heap_p.top()<<'\n';
				heap_p.pop();
			}else{
				int plus = heap_p.top();
				int minus = abs(heap_m.top());
				
				if(plus < minus){ 
					cout<<plus<<'\n';
					heap_p.pop();
				}else{//음수 출력 
					cout<<heap_m.top()<<'\n';
					heap_m.pop();
				}
			}
		}else if(input < 0){
			heap_m.push(input); 
		}else{
			heap_p.push(input);
		}
	}
	
	return 0;
} 
