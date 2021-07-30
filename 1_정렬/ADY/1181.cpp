#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
	if(a.length() == b.length()){
		return a.compare(b) < 0;
	}
	return a.length() < b.length();
		
}

int main(){
	int N;
	string word;
	vector<string> wlist;
	
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>word;
		wlist.push_back(word);
	}
	
	sort(wlist.begin(), wlist.end(), compare);
	
	cout<<wlist[0]<<'\n';
	
	for(int j=1; j<N; j++){
		if(wlist[j-1] == wlist[j])
			continue;
		cout<<wlist[j]<<'\n';
	}
	
	return 0;
}
