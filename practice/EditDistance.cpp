#include <bits/stdc++.h>
using namespace std;

#define FOR(a,b,i) for(int i=a;i<=b;i++)

int main(){
    string a("intension"),b("execution");
    int n = a.length(),m = b.length();
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    FOR(0,n-1,i) dp[i][0] = i;
    FOR(0,m-1,i) dp[0][i] = i;
    FOR(1,n-1,i){
        FOR(1,m-1,j){
            if(a[i] == b[j])
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j] + 1,dp[i][j-1] + 1));
            else
                dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j] + 1,dp[i][j-1] + 1));
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}
