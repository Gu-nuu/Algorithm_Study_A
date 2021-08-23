#include <iostream>
#include <stack>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, pushN, popN, Nsize, sum;
	stack<int> num;
	sum = 0;
		
	cin>>K;
	for(int i=0; i<K; i++){
		cin>>pushN;
		if(pushN == 0){
			num.pop();
		}else{
			num.push(pushN);
		}
	}
	
	Nsize = num.size();
	for(int i=0; i<Nsize; i++){
		sum += num.top();
		num.pop();
	}
	
	cout<<sum;
	
	return 0; 
}
