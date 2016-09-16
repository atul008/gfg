 #include<iostream>
 #include<algorithm>
 #include<vector>
 #include<cstring>
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


 int main(){
    char s[100002];
    cin >> s;
    int len = strlen(s),temp,temp1;
    vi min(10,-1),index(10,-1),ans(len,0);

    min[s[0]-'0'] = 0;
    index[s[0]-'0'] = 0;
    ans[0] = 0;

    repA2B(1,len-1,i){
        //a = min[s[i]-'0'];
        if(min[s[i]-'0'] == -1){
            ans[i] = ans[i-1]+1;
            min[s[i]-'0'] = ans[i];
            index[s[i] -'0'] = i;
        } else{
            temp = min[s[i]-'0'] < ans[i-1]?min[s[i]-'0']:ans[i-1];
            if(index[s[i]-'0']+1 < i){
                temp1 = (ans[index[s[i]-'0']-1] < ans[index[s[i]-'0']+1] ? ans[index[s[i]-'0']-1]:ans[index[s[i]-'0']+1])+1;
                ans[i] = (temp < temp1?temp:temp1) +1;
            } else{
                temp1 = (ans[index[s[i]-'0']-1] +1 < temp ? ans[index[s[i]-'0']-1]+1:temp);
                ans[i] = temp1 + 1;
            }


        }
    }
    cout << "ans : " << endl ;
    rep(len,i) cout << ans[i] << " ";
    cout<<endl;

    cout << "min : " << endl ;
    rep(10,i) cout << min[i] << " ";
    cout<<endl;

    cout << "index : " << endl ;
    rep(10,i) cout << index[i] << " ";
    cout<<endl;

    cout << ans[len-1] << endl;

 return 0;
 }
