#include <iostream>

using namespace std;
int main(){
	int N;
	long long result, cur;
	long long *length;
	int *price;
	cin>>N;
	length = new long long[N-1];
	price = new int[N];
	
	for(int i=0; i<N-1; i++){
		cin>>length[i];
	}
	for(int i=0; i<N; i++){
		cin>>price[i];
	}
	
	result =0;
	cur = price[0];
	
	for(int i=0; i<N-1; i++){
		if(cur > price[i]) cur = price[i];
		result += cur*length[i];
	}
	cout<<result;
	return 0;
}
