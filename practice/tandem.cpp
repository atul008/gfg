 #include <map>
 #include <set>
 #include <cmath>
 #include <string>
 #include <sstream>
 #include <vector>
 #include <iostream>
 #include <algorithm>

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;


 int main(){
    string s;
    int k,n;
    cin >> s >> k;
    s.append(k,'.');
    n = s.length();
    int len = 0;
    int ans = 0;
    for(len = 2;len <= n+k;len+=2){
        FOR(0,(n+k-len),i){
            int flag = 0;
            FOR(i,i-1+len/2,j){
                if(!(s[j] == s[j+len/2] || s[j+len/2] == '.')){
                     flag = 1;
                     break;
                }
            }
            if(flag == 0){
                ans = len;
            }
        }
    }
    cout << ans << endl;

 return 0;
 }
