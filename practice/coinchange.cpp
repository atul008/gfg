#include <bits/stdc++.h>
using namespace std;
#define FOR(a,b,i) for(int i=a;i<=b;i++)
int main(){{};

    int coins[]={1,2,3,4};
    int nc = sizeof(coins)/sizeof(coins[0]);
    int n;
    cin >> n;
    int dp[n+1][nc];
    memset(dp,0,sizeof(dp));

    FOR(0,nc-1,i) dp[0][i] = 1;

    FOR(1,n,i) FOR(0,nc-1,j){
        dp[i][j] = ((j>0)?dp[i][j-1]:0)  + ((i-coins[j] >=0)?dp[i-coins[j]][j]:0);
    }
    cout <<  dp[n][nc-1] << endl;
return 0;
}
