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
 int n,p;
 cin >> p >> n;
 vector<ll> arr(p,-1);
 ll a,count =0,flag = 0;
 FOR(1,n,i){
     cin >> a;
     if(arr[a%p] == -1 && flag == 0){
        count++;
        arr[a%p] = a;
     }else{
        flag = 1;
     }
 }
 if(count == n)
    cout << "-1" << endl;
 else
    cout << count+1 << endl;

 return 0;
 }
