#include <iostream>
#include <limits.h>

using namespace std;

int K, N;
long long* length;

bool possible(long long len){
	if(len == 0) return false;
	else{
	int count = 0;
	for(int i=0; i<K; i++){
		count += length[i] / len;
	}
	return count >= N;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long L, R, mid, max; 
	cin>>K>>N;
	
	length = new long long[K];
	
	L = 0;
	R = LLONG_MAX - 1;
	max = 0;
	
	for(int i=0; i<K; i++){
		cin>>length[i];
	}
	
	while(L<=R){
		mid = (L+R) / 2;
		
		if(possible(mid)){
			L = mid + 1;
			if(mid > max) max = mid; //최대 길이 갱신 
		}else{
			R = mid - 1;
		}
	}
	
	cout<<max;
	 
	return 0;
}
