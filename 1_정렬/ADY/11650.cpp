#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	
	vector<pair<int, int> > dot(N);
	
	for(int i=0; i<N; i++){
		cin>>dot[i].first>>dot[i].second;
	}
	
	sort(dot.begin(), dot.end());
	
	for(int j=0; j<N; j++){
		cout<<dot[j].first<<' '<<dot[j].second<<'\n';
	}
	
	return 0;
}
