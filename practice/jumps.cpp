 #include <bits/stdc++.h>
 #define  F first
 #define  S second

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define RFOR(a,b,i) for(int i=b; i>=a; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 int main(){
  int arr[6] = {1, 3, 6, 1, 0, 9};
  vi minsteps(6,1e8);
  minsteps[0] = 0;
  FOR(0,5,i){
    for(int j = i+1;j<6 && j<=i+arr[i];j++){
        minsteps[j] = min(minsteps[j],minsteps[i] + 1);
    }
  }
  cout << minsteps[5] << endl;
 return 0;
 }

