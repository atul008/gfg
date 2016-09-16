 #include <bits/stdc++.h>
 #define  x first
 #define  y second

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
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
 void popFromQ(stack<int>& s){
    if(!s.empty()){
        int a = s.top();
        s.pop();
        if(!s.empty()){
            popFromQ(s);
            s.push(a);
        }
    }
 }

 int main(){
    stack<int> s;
    FOR(1,5,i) s.push(i);
    popFromQ(s);
    popFromQ(s);
    cout << "after :";
    while(!s.empty()){
         cout << s.top() << " ";
         s.pop();
    }
    cout << endl;

 return 0;
 }
