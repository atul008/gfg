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

 typedef struct suffix{
    int index,r,nr;
 }suffix;
 bool cmp(const suffix a,const suffix b){
        if(a.r == b.r){
            return a.nr < b.nr;
        }else{
            return a.r < b.r;
        }
 }

 void findSuffixArray(string s,vi& SA){
    int n = s.length();
    struct suffix sfx[n];
    int ind[n];
    FOR(0,n-1,i){
         sfx[i].index = i;
         sfx[i].r = s[i]-'a';
         if(i < n-1)
            sfx[i].nr = s[i+1]-'a';
        else
            sfx[i].nr = -1;
    }
    sort(sfx,sfx+n,cmp);
    for(int k = 4;k < 2*n;k = k*2){
        int prev = sfx[0].r;
        int rank = 0;
        sfx[0].r = rank;
        ind[sfx[0].index] = 0;
        FOR(1,n-1,i){
            if(prev == sfx[i].r && sfx[i-1].nr == sfx[i].nr){
                prev = sfx[i].r;
                sfx[i].r = rank;
            }else{
                prev = sfx[i].r;
                sfx[i].r = ++rank;
            }
            ind[sfx[i].index] = i;
        }

        FOR(0,n-1,i){
            int nxtIndex = sfx[i].index + k/2;
            if(nxtIndex < n){
                sfx[i].nr = sfx[ind[nxtIndex]].r;
            }else{
                sfx[i].nr = -1;
            }
        }
        sort(sfx,sfx+n,cmp);
    }
    FOR(0,n-1,i){
        SA[i] = sfx[i].index;
    }

 }
 void search(string& txt,string& pat,vi& sa){
        int n = txt.length();
        int l=0,r = n-1,m;
        while(l < r ){
            m = l + (r-l)/2;
            string ss = txt.substr(sa[m],pat.length());
            cout << " ss : " << ss << endl;
            if(ss == pat){
                cout << "Pat found at : " << m << endl;
                return;
            }else if(ss < pat)
                l = m+1;
            else
                r = m -1;
        }
    cout << " Pat not found \n";
 }


 int main(){
    string s = "banana",pat = "anan";

    vi sa(s.length());
    findSuffixArray(s,sa);
    tr(sa,it) cout << *it << " ";
    cout << endl;
    search(s,pat,sa);
 return 0;

 }
