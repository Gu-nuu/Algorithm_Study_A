#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(int a, int b){
	return a < b;
} 

int main(){
	int N, rate, next_rate;
	
	cin>>N;
	
	int mem[N][3];
	
	for(int i=0; i<N; i++){
		cin>>mem[i][0]>>mem[i][1];
		mem[i][2] = 0;
	}
	
	//덩치비교 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==j) continue;
			if(mem[i][0]<mem[j][0] && mem[i][1]<mem[j][1]){
				mem[i][2]++;
			}
		}
	}
	
	for(int i=0; i<N; i++){
		cout<<mem[i][2] + 1<<' ';
	}
	return 0;
}
