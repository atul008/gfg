     #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<cstring>
    #include<climits>
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
    #define min3(a,b,c) min(a,min(b,c))
    int main(){
    char s[100002];
    cin >> s;
    int len = strlen(s),temp,index,index0;
    vi ans(len,0);
    vvi mini(10);

    mini[s[0]-'0'].pb(0);
    ans[0] = 0;

    vi::iterator it;
    rep1(len,i){
    index = s[i]-'0';
    if(!mini[index].empty()){
    temp = INT_MAX;
    tr(mini[index],it){
    temp = min3(temp,ans[*it]+1,ans[*it-1]+2);
    if(*it+1 < i)
    temp = min(temp,ans[*it+1]+2);
    index0 = mini[index].back();
    }
    ans[i] = min(temp,ans[i-1]+1);
    if(ans[i] <= ans[index0]){
    mini[index].pop_back();
    mini[index].pb(i);
    }
    }else{
    ans[i] = ans[i-1]+1;
    mini[index].pb(i);
    }

    }

    /* rep(10,i){
    if(!mini[i].empty()){
    tr(mini[i],it) cout << *it << " ";
    cout << endl;
    // cout << "hey\n";
    }

    }
    cout << "ans : " << endl ;
    rep(len,i) cout << ans[i] << " ";
    cout<<endl;
    */ cout << ans[len-1] << endl;

    return 0;
    }
