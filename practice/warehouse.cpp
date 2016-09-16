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
 set< ii >::reverse_iterator it;
 for(it = degreeSet.rbegin(); it!=degreeSet.rend();it++){
    if(present(x,it->second)){
        int flag = 0;
        FOR(1,n,i){
            if(v[it->second][i] == 1 && !present(x,i)){
                x.insert(i);
                flag =1;
            }
        }
        if(flag == 1) w.insert(it->second);

    }else{
        w.insert(it->second);
        x.insert(it->second);
        FOR(1,n,i){
            if(v[it->second][i] == 1 && !present(x,i)){
                x.insert(i);
            }
        }
    }
 }
 cout << "w : ";
 tr(w,it) cout << *it << " ";

 cout << "x : ";
 tr(x,it) cout << *it << " ";

cout << endl;
 int ans = w.size() + n-x.size();
 cout << ans << endl;
 return 0;
 }
