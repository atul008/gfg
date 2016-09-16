#include<iostream>
using namespace std;
void swap(char *x,char *y){
	char t;
	t=*x;
	*x=*y;
	*y=t;
}

void permute(char *a,int i,int n){
	if(i==n) cout << a <<endl ;
	else {
		for(int j=i;j<=n;j++){
			swap((a+i),(a+j));  permute(a,i+1,n);  swap((a+i),(a+j));
		}
	}
}

int main(){
	char str[] ="abcdef";
	permute(str,0,5);
return 0;
}
