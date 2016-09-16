 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <string>
 #include <sstream>
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
 #define int64 long long int

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;


 int main(){
    int t,n;
    int64_t ans = 0;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 2*n*(n-1)*(n-1) + 2*(n)*(n-1)*(n-2)*(n-2) + n*(n-1)*(n-2);
        cout << ans << endl;
    }

 return 0;
 }
