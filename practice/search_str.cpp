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
    string s;
    cin >> s;
    int n;
    cin >> n;
    int l,p;
    set<string> st;
    int slen = s.length();
    while(n--){
        cin >> l >> p;
        st.clear();
        FOR(0,slen-l,i){
       // for(int i =0;i<=slen-l;i += l){
                int count = 0;
                string pat = s.substr(i,l);
                if(present(st,pat)) continue;
                string::size_type found = s.find(pat);
                while(found != string::npos){
                    count++;
                    if(count > p) break;
                    found = s.find(pat,found+1);
                }
                if(count == p) st.insert(pat);

        }
    cout << sz(st) << endl;
    }

 return 0;
 }
