#include <iostream>
#include <string>

using namespace std;
int main(){
	string input;
  string num;
	int result = 0;
	bool minus = false;
	cin>>input;
	
	for(int i=0; i<=input.size(); i++){
		if(input[i] == '-' || input[i] == '+' || i == input.size()){
			if(minus){ //앞에 '-'가 존재했을 경우 
				result -= stoi(num);
				num = ""; 
			}else{//앞에 '-'가 없었을 경우 
				result += stoi(num);
				num = "";
			}
			
			if(input[i] == '-') minus = true;
		}else{
			num += input[i]; //숫자항 num에 저장 
		}
	}
	
	cout<<result;	
	return 0;
}
