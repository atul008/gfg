 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>
 #define  x first
 #define  y second

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
 typedef long long ll;


 int main(){
    string s;
    int k,n;
    vi wt(26);
    cin >> s;
    cin >> k;
    int W = -1;
    FOR(0,25,i){
        cin >> wt[i];
        if(W < wt[i]) W = wt[i];
    }
    ll ans = 0;
    FOR(0,s.length()-1,i){
        ans += wt[s[i]-'a']*(i+1);
    }
    //cout << ans << endl;
    n = s.length();
    ans += W*(n*k + k*(k+1)/2);
    cout << ans << endl;
 return 0;
 }
