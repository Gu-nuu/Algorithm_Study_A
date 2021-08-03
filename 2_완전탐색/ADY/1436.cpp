#include <iostream>
#include <string>

using namespace std;

int main(){
	int N, count;
	string num;
	count = 6;
	cin>>N;
	
	if(N <=6){
		cout<<(N-1)*1000+666;
	}else{
		for(int i=6660; count<=10000; i++){
			num = to_string(i);
			if(num.find("666") != string::npos){//666존재 
				count++;
			}
			if(count == N){
				cout<<num;
				break;
			}
		}
	}
	return 0;
}
