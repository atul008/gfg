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
 int n,m,a,b;
 cin >> n >> m;
 vvi v(n+1,vi(n+1,0));
 vi degree(n+1,0);

 FOR(1,m,i){
    cin >> a >> b;
    degree[a]++;
    degree[b]++;
    v[a][b] = 1;
    v[b][a] = 1;
 }

 set< ii > degreeSet;
 FOR(1,n,i){
    if(degree[i] > 0) degreeSet.insert(mp(degree[i],i));
 }

 //vector< ii > dset(all(degreeSet));

 set<int> w,x;
 set< ii >::iterator it;

 for(it = degreeSet.begin(); it!=degreeSet.end();it++){
    int ma=-1,node = -1 ;
    if(!present(x,it->second)){
        FOR(1,n,i){
            if(v[it->second][i] == 1 && !present(w,i) && ma < degree[i]){
                ma = degree[i];
                node = i;
            }
        }
        if(ma != -1 && node != -1){
        w.insert(node);
        //x.insert(it->second);
        x.insert(node);
        FOR(1,n,i){
            if(v[node][i] == 1 && !present(x,i)){
                x.insert(i);
            }
        }
       }

    }
 }
 cout << "w : ";
 tr(w,it) cout << *it << " ";

 cout << "x : ";
 tr(x,it) cout << *it << " ";

 int ans = w.size() + n-x.size();
 cout << ans << endl;
 return 0;
 }
