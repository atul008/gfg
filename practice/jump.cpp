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

 void solve(string& s ,int index,int& count){
    if(index <= 0 )
        return;

    int k=-1;
    repA2B(0,index-1,i)
        if(s[index] == s[i]){
            k = i;
            break;
        }
    if(k>0){
        count++;
        solve(s,k-1,count);
    }
 }

 int main(){
    string s;
    cin >> s;
    int count=0;
   solve(s,s.length()-1,count);
    cout << count+1<< endl;
 return 0;
 }

