#include <iostream>

using namespace std;

int N, M;
long long* tree;

bool possible(long long len){
	if(len == 0) return false;
	else{
	long long total = 0;
	long long after;
	for(int i=0; i<N; i++){
		after = tree[i] - len;
		if(after>0) total += after;
	}
	return total >= M;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long L, R, mid, max, cur;
	cin>>N>>M;
	
	tree = new long long[N];
	
	L = 0;
	R = 0;
	max = 0;
	
	for(int i=0; i<N; i++){
		cin>>cur;
		tree[i] = cur;
		if(cur > R) R = cur;
	}

	while(L<=R){
		mid = (L+R) / 2;
		
		if(possible(mid)){
			L = mid + 1;
			if(mid > max) max = mid;
		}else{
			R = mid - 1;
		}
	}
	
	cout<<max;
	return 0;
}
