 #include <bits/stdc++.h>
 #define  x first
 #define  y second

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define RFOR(a,b,i) for(int i=b; i>=a; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 int dp[100][100];
 void countSubsets(vi& arr,int k){
    int n = sz(arr);
    FOR(0,n,i) dp[i][0] = 1;
    FOR(1,k,i) dp[0][i] = 0;
    FOR(1,n,i){
        FOR(1,k,j){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }

    }
 }

 int main(){

 int n,t;
 cout << " enter array  no. and array : \n";
 cin >> n;
 vi arr(n);
 FOR(0,n-1,i) cin >> arr[i];
 cout << "t :";
 cin >> t;
 vi vis(n,0);
 while(t--){
    cin >> n;
    countSubsets(arr,n);
    cout << dp[sz(arr)][n] << endl;
 }
 return 0;
 }
