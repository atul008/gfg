#include<iostream>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int minPalPat(char *str){
    int n = strlen(str);
    int C[n][n];
    bool P[n][n];

    for(int i =0; i<n;i++){
        P[i][i]  = true;
        C[i][i]  = 0;
    }

    for(int len = 2;len <=n;len++){
        for(int i = 0;i < n-len + 1 ;i++){
            int j = i+len-1;

            if(len == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j] && P[i+1][j-1]);

            if(P[i][j] == true)
                C[i][j] = 0;
            else{
                 C[i][j] = INT_MAX;
                for(int k = i ;k <=j-1;k++ ){
                    C[i][j] = min(C[i][j],C[i][k] + C[k+1][j] + 1);
                }
            }
        }
    }
    return C[0][n-1];
}


int main(){
 char str[] = "ababbbabbababa";
 cout << "Min cut for palindrome partioning: " << minPalPat(str) << endl;
return 0 ;

}
