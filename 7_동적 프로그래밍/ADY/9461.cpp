#include <iostream>

using namespace std;

long long Plist[100];

long long P(int N){
	if(N<=3) return 1;
	if(N<=5) return 2;
	if(Plist[N] != NULL) return Plist[N];
	
	Plist[N] = P(N-1) + P(N-5);
	return Plist[N];
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T, N;
	cin>>T;
	
	for(int i=0; i<T; i++){
		cin>>N;
		cout<<P(N)<<'\n';
	}
	
	return 0;
}
