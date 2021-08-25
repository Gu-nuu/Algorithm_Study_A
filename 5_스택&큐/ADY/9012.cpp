#include <iostream>
#include <stack>

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	bool unbal;
	string pushN;
	stack<char> input;

	cin>>T;
	for(int i=0; i<T; i++){
		unbal = false;
		pushN = "";
		cin>>pushN;
		for(int j=0; j<pushN.size(); j++){
			if(pushN[j] == '(') {
				input.push(pushN[j]);
			}else if(pushN[j] == ')'){
				if(input.size() == 0){
					unbal = true;
					break;
				}else{
					input.pop();
				}
			}
		}
		// '(' 가 모두 매칭되지 않고 남아있으면 VPS가 아니게됨 
		if(input.size() != 0) unbal = true;  
		while(!input.empty()) input.pop(); //스택 초기화 
		
		if(!unbal) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
