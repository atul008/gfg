#include<iostream>
#include<string.h>
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


//convert string x to y with  min edits.
int min_edit(char *x,char *y){
	int m,n;
	m = strlen(x);
	n = strlen(y);
	int arr[m+1][n+1];
	
	arr[0][0] = 0;
	for(int i = 1;i<=m;i++)
		arr[i][0] = i;
		 	
	for(int j = 1;j<=n;j++)
		arr[0][j] = j;
	
	for(int i = 1; i <= m; i++){
		for(int j =1; j <= n; j++){
			arr[i][j] = min(arr[i-1][j] + 1, //insertion
					arr[i][j-1] + 1, // deletion
					arr[i-1][j-1]+ (x[i-1] == y[j-1]?0:1)); // substitution		
		
		}
	}
	//display(arr,m,n);
	
	cout << "Edit Matrix \n";
	for(int i = 0;i <= m; i++){
		for(int j = 0;j <= n; j++){
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	} 
	
	return arr[m][n];
}

int main(){
	char *a;
	a = "'sunday'";
	char *b;
	b = "'saturday'";
	cout << "Min edits from  "<< a << " to " << b <<" : "<< min_edit(a,b) << endl; 

	return 0;
}

