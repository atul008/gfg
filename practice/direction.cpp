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
 typedef long long ll;

 int main(){
 int n,m;
 cin >> n >> m;

 vi dir(n+1,0);
 char x;
 int l,r;
 while(m--){
     cin >> x;
     ll k;
     if(x == 'A' || x == 'C'){
        cin >> l >> r >> k;
        k = k%4;
        if(x == 'C'){
            FOR(l,r,i){
                dir[i] = (dir[i]+k)%4;
            }
        }else{
            FOR(l,r,i){
                FOR(1,k,j){
                    dir[i]--;
                    if(dir[i] < 0) dir[i] = dir[i] + 4;
                }
            }
        }
     }else{
        cin >> l >> r;
        vi count(4,0);
        FOR(l,r,i){
            count[dir[i]]++;
        }
        int ans = *(max_element(all(count)));
        cout << ans << endl;
    //    tr(dir,it) cout << *it << " ";
     //   cout << endl;
     }
 }


 return 0;
 }
