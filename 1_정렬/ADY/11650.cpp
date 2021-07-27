#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int N;
	cin>>N;
	
	vector<pair<int, int> > dot(N);
	
	for(int i=0; i<N; i++){
		cin>>dot[i].second>>dot[i].first;
	}
	
	sort(dot.begin(), dot.end());
	
	for(int j=0; j<N; j++){
		cout<<dot[j].second<<' '<<dot[j].first<<'\n';
	}
	
	return 0;
}
