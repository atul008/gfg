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
 int64_t n,m,h,c,t,count=0,cost=0;
 cin >> n >> m >> h;
 set< pair<int64_t,int64_t> > s;
 set< pair<int64_t,int64_t> >::iterator p;
 FOR(0,h-1,i){
    cin >> t >> c;
    s.insert(mp(c,t));
    count += t;
 }
 if(count < (n*m)){
    cout << "Impossible" << endl;
 }else{
    int64_t left = n*m;
    while(!s.empty() && left > 0 ){
        p = s.begin();
        if(left >= p->second){
            cost = cost + (p->first)*(p->second);
            left = left - p->second;
        }else{
            cost = cost + (p->second - left)*(p->first);
            left = 0;
        }
        s.erase(p);
    }
    cout << cost << endl;
 }
 return 0;
 }
