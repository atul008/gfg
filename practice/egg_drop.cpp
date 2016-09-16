#include<iostream>
#include<limits.h>
using namespace std;
int max(int a,int b){

return (a > b?a:b);
}

int eggDrop(int n,int k){
	int egg[n+1][k+1],res;
	//n = no of eggs and k = no of floors.
	for(int i = 0 ;i <= n;i++){
		egg[i][0] = 0;
		egg[i][1] = 1; 
	} 
	for(int j = 2 ;j <= k ;j++)
		egg[1][j] = j;
		
	for(int i = 2;i <= n;i++){
		for(int j = 2; j<= k; j++){
			egg[i][j] = INT_MAX;
			for(int x = 1 ;x <=j; x++){
				res = 1 + max(egg[i-1][x-1],egg[i][j-x]);
				if(res < egg[i][j])
					egg[i][j] = res; 
			} 
		}
	}  
	return egg[n][k];
}


int main(){
	int n = 2,k = 4;
	
	cout << "Minimum no. of trails : " << eggDrop(n,k) << endl ;
	return 0;
}

