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
// vvi v(n+1,vi(n+1,0));
 int v[1005][1005];
 //FOR(0,1004,i)
 SET(v,0);
 //vi degree(n+1,0);
 int degree[1005];
 SET(degree,0);
 FOR(1,m,i){
    cin >> a >> b;
    degree[a]++;
    degree[b]++;
    v[a][b] = 1;
    v[b][a] = 1;
 }

 set<int> w,x;

 FOR(1,n,i){
   if(!present(x,i)){
       int mdegree = degree[i],node = i;
       int mdegree1 = degree[i],node1 = i;
       FOR(1,n,j){
            if(v[i][j] == 1 && mdegree < degree[j] && !present(x,j)){
                mdegree = degree[j];
                node = j;
            }
            if(v[i][j] == 1 && mdegree1 < degree[j]){
                mdegree1 = degree[j];
                node1 = j;
            }
       }
       if(node != i){
           w.insert(node);
           x.insert(node);
           FOR(1,n,j){
                if(v[node][j] == 1 && !present(x,j))
                    x.insert(j);
           }
       } else {
           w.insert(node1);
           x.insert(node1);
           FOR(1,n,j){
                if(v[node1][j] == 1 && !present(x,j))
                    x.insert(j);
           }
       }

    }
 }
 /*cout << "w : ";
 tr(w,it) cout << *it << " ";
 cout << endl;
 cout << "x : ";
 tr(x,it) cout << *it << " ";
 cout << endl;
 */
 int ans = sz(w);
 cout << ans << endl;
 return 0;
 }
