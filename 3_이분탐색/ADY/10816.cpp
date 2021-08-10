#include <iostream>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, num, mid, L, R, cur;
	int* card;
	int* target;
	bool found;
	card = new int[20000001];
	
	cin>>N;
	
	for(int i=0; i<N; i++){
		cin>>num;
		card[num+10000000]++;
	}
	
	cin>>M;
	target = new int[M];
	
	for(int i=0; i<M; i++){
		cin>>target[i];
	}
	
	for(int i=0; i<M; i++){
		cur = target[i] + 10000000;
		found = false;
		L = 0;
		R = 20000001;
		while(L<=R){
			mid = (L+R) / 2;
			if(cur == mid){
				cout<<card[cur]<<' ';
				found = true;
				break;
			}else if(cur < mid){
				R = mid - 1;
			}else{
				L = mid + 1;
			}
		}
		if(!found) cout<<'0 ';
	}
	
	return 0;
}
