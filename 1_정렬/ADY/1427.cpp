#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char temp;
    int j;
    char n[11] = {NULL};
    cin>>n;
    
    for(int i=0; i<strlen(n)-1; i++){
       j = i;
        while(j>=0 && n[j] < n[j+1]){
            temp = n[j];
            n[j] = n[j+1];
            n[j+1] = temp;
            j--;
        }
    }
    
    printf("%s", n);
    return 0;
}
