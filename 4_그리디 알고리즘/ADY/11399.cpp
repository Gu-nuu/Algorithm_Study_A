#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, sum;
	int *time;
	sum = 0;
	cin>>N;
	time = new int[N];
	
	for(int i=0; i<N; i++){
		cin>>time[i];
	}
	
	sort(time, time+N);
	for(int i=1; i<=N; i++){
		sum += time[N-i] * i;
	}
	cout<<sum;
	return 0;
}
