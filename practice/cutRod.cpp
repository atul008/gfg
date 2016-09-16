#include <bits/stdc++.h>
using namespace std;

#define FOR(a,b,i) for(int i=a;i<=b;i++)

int main(){

    string s("GEEKS FOR GEEKS");
    int n = s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    FOR(0,n-1,i) dp[i][i] = 1;

    FOR(2,n,len){
        FOR(0,n-len,i){
            int j = i+len-1;
            if(s[i]== s[j] && len == 2) dp[i][j] = 2;
            else if(s[i]== s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;

return 0;
}
