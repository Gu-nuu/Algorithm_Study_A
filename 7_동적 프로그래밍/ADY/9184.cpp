#include <iostream>

using namespace std;

int list[21][21][21];

int w(int a, int b, int c){
	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	else if(a > 20 || b > 20 || c > 20){
		return w(20, 20, 20);
	}
	else if(list[a][b][c] != NULL){//존재하는 값 반환 
		return list[a][b][c];
	}
	else if(a < b && b < c){
		list[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return list[a][b][c];
	}
	else{
		list[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		return list[a][b][c];
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(1){
		int a, b, c;
		cin>>a>>b>>c; 
		if(a == -1 && b == -1 && c == -1){
			break;
		}
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a, b, c)<<'\n';
	}
	
	return 0;
}
