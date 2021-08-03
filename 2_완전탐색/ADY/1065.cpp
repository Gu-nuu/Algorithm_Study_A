#include <iostream>

using namespace std;

int main(){
	int N, count;
	count = 0;
	cin>>N;
	
	for(int i=1; i<=N; i++){
		if(i<100) count++;
		else{
			if(i/100 - (i%100)/10 == (i%100)/10 - i%10){
				count++;
			}
		}
	}
	
	cout<<count;
	return 0;
}
