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
 int n,k,c;
 cin >> n >> k >> c;
 vi bc(n);
 FOR(0,n-1,i) cin >> bc[i];
 int maxAns=0,ans=0;
 FOR(1,n-1,i){
    if(c == bc[i] && bc[i-1] == bc[i] ){
        int l = i-2;
        int r = i+1;
        int count = 2;
        while(l>=0 && r <=n-1){
            if(bc[l] == bc[r]){
                if(bc[l-1] == bc[l] && bc[r] == bc[r+1] && r+1 < n && l -1 >=0 ){
                    count +=4;
                    l = l-2;
                    r = r+2;
                }else if(bc[l-1] == bc[l]){
                    count +=3;
                    l = l-2;
                    r = r+1;
                } else if(bc[r] == bc[r+1]){
                    count +=3;
                    l = l-1;
                    r =r+2;
                } else break;

            }else{
                break;
            }
        }
    ans = count;
    }
    maxAns = max(maxAns,ans);

 }
 cout << maxAns;
 return 0;
 }
