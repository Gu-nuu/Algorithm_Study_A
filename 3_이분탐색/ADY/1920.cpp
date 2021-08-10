#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, mid, L, R, cur;
	int* arrN;
	int* arrM;
	bool found;
	
	cin>>N;
	arrN = new int[N];
	
	for(int i=0; i<N; i++){
		cin>>arrN[i];
	}
	sort(arrN, arrN+N);
	
	
	cin>>M;
	arrM = new int[M];
	
	for(int i=0; i<M; i++){
		cin>>arrM[i];
	}
	
	for(int i=0; i<M; i++){
		cur = arrM[i];
		found = false;
		L = 0;
		R = N-1;
		while(L<=R){
			mid = (L+R) / 2;
			if(cur == arrN[mid]){
				found = true;
				break;
			}else if(cur < arrN[mid]){
				R = mid - 1;
			}else{
				L = mid + 1;
			}
		}
		cout<<found<<'\n';
	}
	
	
	
	return 0;
}
