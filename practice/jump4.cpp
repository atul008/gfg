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
 void pacifyF(char* s,int len,vi& ans,vvi& mini,vi& minIndex,int k);
 void pacifyB(char* s,int len,vi& ans,vvi& mini,vi& minIndex,int k){
    int flag = 1,index;
    vi::iterator it;
      while(flag == 1 && k >0){
            flag = 0;
            index = s[k-1]-'0';
            if(ans[k]+1 < ans[k-1]){
                ans[k-1] = ans[k] + 1;
                flag = 1;
                if(ans[k-1] < ans[minIndex[index]]){
                    minIndex[index] = k-1;
                }
                tr(mini[index],it){
                    if(ans[*it] > ans[k-1]+1){
                        ans[*it] = ans[k-1]+1;
                        pacifyB(s,len,ans,mini,minIndex,*it-1);
                        pacifyF(s,len,ans,mini,minIndex,*it+1);
                    }
                }
            }
            k--;
        }
 }

 void pacifyF(char* s,int len,vi& ans,vvi& mini,vi& minIndex,int k){
    int flag = 1,index;
        while(flag == 1 && k < len){
            flag = 0;
            index = s[k+1]-'0';
            if(ans[k]+1 < ans[k+1]){
                ans[k+1] = ans[k] + 1;
                flag = 1;
                if(ans[k+1] < ans[minIndex[index]]){
                    minIndex[index] = k+1;
                }
                tr(mini[index],it){
                    if(ans[*it] > ans[k+1]+1){
                        ans[*it] = ans[k+1]+1;
                        pacifyB(s,len,ans,mini,minIndex,*it-1);
                        pacifyF(s,len,ans,mini,minIndex,*it+1);
                    }
                }
            }
            k++;
        }
 }

 int main(){
    char s[100002];
    cin >> s;
    int len = strlen(s),index,index0;
    vi ans(len,INT_MAX),minIndex(10,-1);
    vvi mini(10);
    vi::iterator it;

    mini[s[0]-'0'].pb(0);
    ans[0] = 0;
    minIndex[s[0]-'0'] = 0;
    rep1(len,i){
        index = s[i]-'0';
        mini[index].pb(i);
        if(minIndex[index] != -1){
            ans[i] = min(ans[minIndex[index]]+1,ans[i-1]+1);
            if(ans[i] < ans[minIndex[index]])
                minIndex[index] = i;
        }else{
            ans[i] = ans[i-1] + 1;
            minIndex[index] = i;
        }
        pacifyB(s,i,ans,mini,minIndex,i);
    }

    rep(10,i) cout << minIndex[i] << " ";

    cout <<"\n" <<  "ans : " << endl ;
    rep(len,i) cout << ans[i] << " ";
    cout<<endl;
    cout << ans[len-1] << endl;

 return 0;
 }
