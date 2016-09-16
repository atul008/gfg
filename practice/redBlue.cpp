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
 #define first x
 #define second y

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
    int n,m;
    cin >> n >> m;
    vi points(n,0);
    map<int,int> hmap;
    vector < ii > seg;
    FOR(0,n-1,i) cin >> points[i];
    vi pts(all(points));
    FOR(0,m-1,i){
        int a,b;
        cin >> a >> b;
        seg.pb(mp(a,b));
    }
    sort(all(pts));
    FOR(0,n-1,i){
        int t;
        if(i%2 == 0) t= 0;
        else t = 1;
        hmap.insert(mp(pts[i],t));
    }
    FOR(0,n-1,i){
        cout << hmap[points[i]] << " ";
    }
 return 0;
 }
