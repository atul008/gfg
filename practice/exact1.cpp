 #include <map>
 #include <set>
 #include <cmath>
 #include <cstdio>
 #include <string>
 #include <sstream>
 #include <vector>
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

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;


 int main(){
    int n;
    cin >> n;
    vector<double> prob(n);
    FOR(0,n-1,i) cin >> prob[i];
    sort(all(prob));
    double ans = 0,prod = 1;
    for(int i = n-1;i>=0;i--){
        if(ans*(1-prob[i]) + prod*prob[i] > ans){
            ans = ans*(1-prob[i]) + prod*prob[i];
            prod *= (1-prob[i]);
        }
    }
    printf("%.10lf\n",ans);
 return 0;
 }
