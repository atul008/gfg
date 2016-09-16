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
    int n;
    cin >> n;
    vector<set<string> > s(26);
    string str;
    vector< ii > freq(26);

    FOR(1,n,i){
        cin >> str;
        s[str[0]-'A'].insert(str);
    }

    FOR(0,25,i){
        freq[i].first = s[i].size();
        freq[i].second = i;
    }
    sort(all(freq));

    vector<string> lst;
    int fr = freq[25].first;
    int start = freq[25].second;
    freq[25].first--;
    lst.pb(*(s[start].begin()));
    s[start].erase(s[start].begin());

    if(lst.size() > 0)while(1){
        int flag = 0;
        string str = lst.back();
        start = str[str.length()-1]-'A';
        int size = lst.size();
        sort(all(freq));
       // cout << "c2\n";

      for(int i=25;i>=0 && freq[i].first > 0;i--){
                int end = freq[i].second;
             //   cout << "start : " << start << endl;
             //   cout << "end : " << end << endl;
               if(s[start].size() > 0){
                set<string>::iterator it;
                for(it = s[start].begin();it != s[start].end();it++){
                    string stg = *it;
                    if((stg[stg.length()-1]-'A') == end){
                        lst.pb(stg);
                        //freq[i].first--;
                        FOR(0,25,i){
                            if(freq[i].second == start) {
                                freq[i].first--;
                                break;
                            }
                        }
                        s[start].erase(it);
                        flag = 1;
                        break;
                    }
                }
             }
            if(flag ==1 ) break;
        }


        if(size == lst.size()) break;
    }
   // tr(lst,it) cout << *it << endl;
    FOR(0,sz(lst)-1,i) cout << lst[i] << endl;
 return 0;
 }
