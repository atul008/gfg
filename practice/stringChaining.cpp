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
 int n,r1,r2;
 string s;
 vector<string> v;
 vector< vector<string> > vs(26);
 vector< vector<string> >::iterator it;
 FOR(0,n-1,i){
     cin >> s;
     vs[s[i]].pb(s);
  }
  r1 = rand()%26;
  r2 = rand()%(vs[r1].size());
  char l = vs[r1][r2][vs[r1][r2].size()-1] ;
  cout << vs[r1][r2] << endl;
  vs.erase(vs[r1][r2]);
  while(vs[l-'A'].size() > 0){
  r2 = rand()%(vs[r1].size());
  l = vs[r1][r2].back() ;
  cout << vs[r1][r2] << endl;
   r2 = rand()%(vs[l-'A'].size());
   vs.erase(vs[r1][r2]);
  }


  return 0;
 }
