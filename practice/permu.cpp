 #include<iostream>
 #include<algorithm>
 #include<vector>
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

 void allPermu(string& s,int beg,int end){
    if(beg == end){
        cout << s << endl;
        return;
    }
     repA2B(beg,end,i){
        swap(s[beg],s[i]);
        allPermu(s,beg+1,end);
        swap(s[i],s[beg]);
     }

 }

 int main(){
    string s("abc");
    allPermu(s,0,s.length()-1);
 return 0;
 }

