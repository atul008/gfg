#include <set>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <cstdlib>
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

int gcd(int a,int b){
if(b==0) return a;
return gcd(b,a%b);
}
int goodGcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
int main(){
cin.sync_with_stdio(false);
int n,arr[100005],ans =0;

cin >> n;
FOR(0,n-1,i) cin >> arr[i];
FOR(0,n-1,i){
for(int j = i+1;j<n;j++){
for(int k = j+1;k<n;k++){
if(goodGcd(goodGcd(arr[i],arr[j]),arr[k]) == 1 )
ans++;
}
}
}

cout << ans << endl;


return 0;
}
