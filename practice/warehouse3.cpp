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
       int node = i,maxCount = 0;
       vi neigh,neighCount;
      int thisCount = 0;
       FOR(1,n,k){
            if(v[i][k] == 1 && !present(x,k))
                thisCount++;
       }

       FOR(1,n,j) if(v[i][j] == 1){
            //1's neighbour-3
            int count = 0;
            //counts nodes which are uninserted for each neighbour.
            FOR(1,n,k){
                if(v[j][k] == 1 && !present(x,k))
                    count++;
            }
            if(maxCount <= count){
                maxCount = count;
                neigh.pb(j);
                neighCount.pb(maxCount);
            }
        }

 /*
        cout << "neigh : ";
        tr(neigh,it) cout << *it << endl;
        cout << endl;


        cout << "neighCount : ";
        tr(neighCount,it) cout << *it << endl;
        cout << endl;
*/
    if(sz(neighCount) > 0){
       maxCount = neighCount.back();
       if(thisCount < maxCount){
        node = neigh.back();
        for(int j = neighCount.size()-1;j>=0;j--){
            if(neighCount[j] < maxCount)
                break;
            if(!present(x,neigh[j])){
                node = neigh[j];
                break;
            }
        }
       }
    }


  //      cout << "i :" << i << endl;
  //      cout << "node : " << node << endl;
        w.insert(node);
        x.insert(node);
        FOR(1,n,j){
            if(v[node][j] == 1 && !present(x,j))
                x.insert(j);
        }
    }
 }
/* cout << "w : ";
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
