#include <iostream>
#include <queue>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, pushN;
	queue<int> card;
	cin>>N;
	
	for(int i=1; i<=N; i++){
		card.push(i);
	}
	
	while(card.size() != 1){
		card.pop();//맨 앞의 숫자 제거 
		if(card.size() == 1) break;
		card.push(card.front());//그 다음의 숫자 뒤로 옮기기 
		card.pop();
	}
	
	cout<<card.front();
	return 0;
} 
