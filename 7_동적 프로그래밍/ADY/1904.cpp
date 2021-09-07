#include <iostream>

using namespace std;

long long num[1000000];

long long tile(int N){
	if(N == 1) return 1;
	else if(N == 2) return 2;
	
	if(num[N] != NULL) return num[N];
	
	num[N] = tile(N-1) + tile(N-2);
	return num[N]%15746;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin>>N;
	
	cout<<tile(N);
	return 0;
}
