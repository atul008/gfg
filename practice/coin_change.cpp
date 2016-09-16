#include<iostream>
using namespace std;

int coinChange(int *s,int m,int n){
	int table[n+1][m] , x, y ;
	
	for(int j = 0 ;j < m ; j++)
		table[0][j] = 1;
		
	for(int i = 1 ;i < n+1 ;i++){
		for(int j = 0;j < m ;j++){
			
			if( i - s[j] >=0)
			    x = table[i-s[j]][j]; 
			 else 
			    x = 0 ;
			if(j > 0)
			    y = table[i][j-1];
			else
			    y = 0;
			
			table[i][j] = x + y;
		}
	}
	return table[n][m-1];
}

int main(){
  int s[3] = {1,2,3}, coins = 3;
  //cout << "Enter no. of coins\n" ; cin >> coins ;
 // cout << "Enter coins\n"; for(int i =0 ;i < coins ;i++) cin >> s[i] ; 
  
  int n = 5;
  cout << "No. of solutions : " << coinChange(s,coins,n) << endl;
 return 0;	
}



