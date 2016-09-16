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
 #define  x first
 #define  y second

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
 int n,ans,maxans = 1;
 cin >> n;
 vector<ll> arr(n);
 FOR(0,n-1,i) cin >> arr[i];

 int count;
 FOR(0,n-2,i){
    int j = i+1,k;
    count = 0;
    ans = 1;
    while(j<=n-1){
        if(arr[i] >= arr[j]){
            count++;
            ll temp = arr[i] + 1;
           if(i > 0 ){ if(j+1 <= n-1 && temp >= arr[j+1]){
                    ans++;
                    break;
                }
            }
            if(count == 2)
                break;
            k = j;
        }
        i++;
        j++;
        ans++;
    }
    if(count == 2){
        i = k-1;
    }
    if(maxans < ans)
        maxans = ans;
 }

cout << maxans << endl;
 return 0;
 }
