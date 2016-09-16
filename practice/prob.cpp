 #include<iostream>
 #include<algorithm>
 #include<vector>
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;
 #define sz(a) int((a).size())
 #define pb push_back
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define rep(a,i) for(int i =0; i<a; i++)
 #define rep1(a,i) for(int i=1; i<a ;i++)
 #define repA2B(a,b,i) for(int i=a; i<=b; i++)
 ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
 }

 int main(){
    int t;
    ll n,m,oddA,oddB,evenA,evenB,num,den,g;
    cin >> t;
    while(t--){
        cin >> n >> m;
        oddA = n%2==0?n/2:(n+1)/2;
        oddB = m%2==0?m/2:(m+1)/2;

        evenA = n-oddA;
        evenB = m-oddB;
        num = oddA*evenB + oddB*evenA;
        den = n*m;
        if(num !=0){
            g = gcd(num,den);
            num/=g;
            den/=g;
        }
        cout << num <<"/"<<den << endl;

    }
     return 0;
 }

