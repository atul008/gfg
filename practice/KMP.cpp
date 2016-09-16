 #include <bits/stdc++.h>
 #define  x first
 #define  y second

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
 void computePrefixArray(string& p,vi& pa){
    pa[0] = 0;
    int k = 0;
    FOR(2,p.length()-1,q){
        while(k > 0 && p[k+1] != p[q])
            k = pa[k];
        if(p[k+1] == p[q])
         k++;
        pa[q] = k;
    }
 }
 void kmp(string& T,string& P){
    int n = T.length(), m = P.length(),flag =0;
    vi pa(m+1);
    computePrefixArray(P,pa);
    int q =0;
    FOR(0,n-1,i){
        while(q > 0 && P[q+1] != T[i])
            q = pa[q];
        if(P[q+1] == T[i]) q++;
        if(q == m-1){
            flag = 1;
            cout << i-m+1 << endl;
            q = pa[q];
        }
    }
    if(flag == 0) cout << endl;
 }
 int main(){
    int m;
    string T,P;
    while(cin >> m){
        //cin >> P >> T;
        getchar();
        getline(cin,P);
        getline(cin,T);
        T = " " + T;
        P = " " + P;
        kmp(T,P);
    }
 return 0;
 }
