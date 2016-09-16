 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <string>
 #include <stdlib.h>
 #include <cstring>
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 #define sz(a) int((a).size())
 #define pb push_back
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define rep(a,i) for(int i =0; i<a; i++)
 #define rep1(a,i) for(int i=1; i<a ;i++)
 #define repA2B(a,b,i) for(int i=a; i<=b; i++)
 #define MP(a,b) make_pair(a,b)

 int main(){
    int t,n;
    char a,b;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        map<char,char> rules;
        map<char,char>::const_iterator it;
        rep(n,i){
            cin >> a >> b;
            rules.insert(MP(a,b));
        }
        cin >> s;
        int len = s.length();
       if(!rules.empty()){
            rep(len,i){
                it = rules.find(s[i]);
                if(it == rules.end()) continue;
                s[i] = it->second;
            }
        }

        int i=0;
        while(s[i]=='0') i++;

        int j = len -1;

        size_t found = s.find('.');
        if(found != string::npos){
            while(s[j]=='0') j--;
            if((s[j]=='.')) j--;
        }

        j = j-i;
        string str = s.substr(i,j+1);
        if(str.empty())
            cout << 0 << endl;
        else
            cout << str << endl;

    }

 return 0;
 }
