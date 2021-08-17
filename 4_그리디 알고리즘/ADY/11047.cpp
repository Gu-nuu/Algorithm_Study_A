#include <iostream>

using namespace std;
int main(){
	int N, K, A, left, count, cur;
	int *price;
	cin>>N>>K;
	count = 0;
	left = K;
	cur = -1;
	price = new int[N];
	
	for(int i=0; i<N; i++){
		cin>>A;
		price[i] = A;
		if(A > K){
			if(price[i-1] <= K){
				cur = i-1;
			}
		}
	}
	
	if(cur < 0) cur = N-1;
	
	while(1){
		if(left>0){
			count++;
			left -= price[cur];
		}else if(left == 0){
			break;
		}else{
			count--;
			left += price[cur];
			cur--;
		}
	}
	
	cout<<count;
	return 0;
}
