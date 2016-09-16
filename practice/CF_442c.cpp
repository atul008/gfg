 #include <bits/stdc++.h>
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
 bool comp(const int& lhs,const int& rhs){
    return (lhs > rhs);
 }

 int main(){
 int n,a,b;
 list<int> l;
 cin >> n;
 FOR(0,n-1,i){
    cin >> a;
    l.pb(a);
 }
 int ans = 0;
 list<int>::iterator i,m;
 vi v(all(l));
 make_heap(all(v),comp);

 while(l.size() > 2){
    //cout << "size : " << l.size() << endl;
   int k = v.front();
    pop_heap(all(v),comp);        //log(n)
    v.pop_back();
    tr(v,it) *it =*it-k;         //O(n)
    // cout << "min : "  << k << endl;
    ans += (l.size()-2)*(k);
    tr(l,it) *it =*it-k;        //O(n)
    i = find(all(l),0);         //O(n)
    if((i != l.begin() && i != (--l.end()))) {
        i++;
        a = *i;
        i--;
        i--;
        b = *i;
        i++;
        ans += min(a,b);
    }
    l.erase(i);
 }
 cout << ans << endl;
 return 0;
 }
