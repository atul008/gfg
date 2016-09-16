#include<iostream>
using namespace std;

int min(int a ,int b ,int c){
	
	int min;
	if(a < b){
		if(a < c)
		  min = a;
		else
		  min = c;
	} else {
		if( b < c)
		 min = b;
		else 
		min = c; 
	}
	return min;
}

int minCost(int mat[3][3],int m,int n){
	int cost[m][n];
	cost[0][0] = mat[0][0];
	
	for(int i = 1 ;i < m; i++)
		cost[i][0] = cost[i-1][0] + mat[i][0];
	
	for(int j = 1 ;j < n; j++)
		cost[0][j] = cost[0][j-1] + mat[0][j];
	
	for(int i = 1; i < m; i++){
		for(int j =1 ; j < n; j++){
			cost[i][j] = min(cost[i-1][j-1], cost[i-1][j], cost[i][j-1] ) + mat[i][j] ; 
			
		} 
	} 
	
	cout << "Cost Matrix \n";
	for(int i = 0;i < m; i++){
		for(int j = 0;j < n; j++){
			cout << " " << cost[i][j] << " ";
		}
		cout << endl;
	} 
	
	return cost[m-1][n-1];
}

int main(){
	int mat[3][3] ={ {1,2,3},
			 {4,8,2},	
			 {1,5,3}
			};
	cout << "Min cost path : " << minCost(mat,3,3) << endl;
	

return 0;
}

