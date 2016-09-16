#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int lip(char *str){
 int n = strlen(str);
int lip[n][n];

for(int i =0 ;i< n;i++){
 lip[i][i] = 1;
}

for(int len =2 ;len<=n;len++){
    for(int i =0;i < n-len+1;i++){
      int j = i+len -1;

      if(str[i] == str[j] && len == 2){
        lip[i][j] = 2;
      } else if(str[i] == str[j]){
            lip[i][j] =lip[i+1][j-1] + 2;
      }else{
       lip[i][j] = max(lip[i+1][j],lip[i][j-1]);
      }
    }
}
return lip[0][n-1];
}

int main(){
 char str[] = "bacb";
 cout << "Longest subsequence palindrome : " << lip(str)<< endl;
return 0;
}
