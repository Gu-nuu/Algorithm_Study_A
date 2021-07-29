#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main(){
	int N;
	cin>>N;
	
	vector<pair<int, string> > member(N);
	
	for(int i=0; i<N; i++){
		cin>>member[i].first>>member[i].second;
	}
	
	stable_sort(member.begin(), member.end(), compare);
	
	for(int j=0; j<N; j++){
		cout<<member[j].first<<' '<<member[j].second<<'\n';
	}
	return 0;
}
