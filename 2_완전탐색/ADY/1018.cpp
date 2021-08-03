#include <iostream>

using namespace std;

int main(){
   int N, M, count, min;
   char data;
   min = 0;
   cin>>N>>M;
   char **board = new char*[N];
   for(int i=0; i<N; i++){
		board[i] = new char[M];
   }
   
   for(int i=0; i<N; i++){
       for(int j=0; j<M; j++){
           cin>>data;
		   board[N][M] = data;
       }
   }
   
   for(int i=0; i<=N-8; i++){
      for(int j=0; j<=M-8; j++){
         count = 0;
         for(int a=0; a<8; a++){
            for(int b=0; b<8; b++){
               if((a+b) % 2 ==0){
                  if(board[i+a][j+b] == 'W'){
                  	count++;
				  }
               }
               else if((a+b) % 2 == 1){
                   if(board[i+a][j+b] == 'B'){
                   		count++;
				   }  
               }
            }
         }
          if(min>count) min = count;
          count = 0;

         for(int a=0; a<8; a++){
            for(int b=0; b<8; b++){
               if((a+b) % 2 ==0){
                  if(board[i+a][j+b] == 'B'){
                  	count++;
				  }
               }
               else if((a+b) % 2 == 1){
                   if(board[i+a][j+b] == 'W'){
                   		count++;
				   }  
               }
            }
         }
          if(min>count) min = count;
      }
   }

   cout<<min;
   return 0;
}
