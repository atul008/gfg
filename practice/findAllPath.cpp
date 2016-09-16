 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
int n;
vvi rPath;
vi maxCap;
void util(const vvi& graph,vi path,vi& vis,int cap,int s,const int d){
    path.pb(s);
  //  cout << "Pushed : " << s << endl;
    if(s == d){
      if(cap >= maxCap.back()){
       maxCap.pb(cap);
       rPath.pb(path);
      }
     return;
    }
    FOR(1,n,i){
       int t = cap;
        if(graph[s][i] > 0 && !vis[i]){
            if(graph[s][i] < t)
                t = graph[s][i];
             vis[i] = 1;
            util(graph,path,vis,t,i,d);
            vis[i] = 0;
        }
    }
  //  cout << "Poped : " << path.back() << endl;
    path.pop_back();

}

 void findPath(const vvi& graph,const int s,const int d){
    vi path;
    vi vis(n+1,0);
    vis[0] = 1;
    vis[s] = 1;
    util(graph,path,vis,INT_MAX,s,d);
 }

 int main(){
    int m,a,b,c,s,d,pas,trip;
    cin >> n >> m;
    maxCap.pb(-1);
    vvi graph(n+1,vi(n+1,0));
    FOR(1,m,i){
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> s >> d >> pas;
    findPath(graph,s,d);
 //   cout << ":::::: ";
    maxCap.erase(maxCap.begin());

    int mCapacity = maxCap.back();
    int k=0;
    FOR(0,maxCap.size()-1,i){
        if(maxCap[i] < mCapacity){
            k++;
        }
    }

    vector<string> p;
    for(int i = k;i<rPath.size();i++){
        stringstream ss;
        string str;
        for(int j = 0;j<rPath[i].size();j++)
            ss << rPath[i][j];
        ss >> str;
        p.pb(str);
    }

    sort(all(p));
    for(int i = 0;i < p[0].length();i++){
        if(i < p[0].length()-1)
            cout << p[0][i] << " ";
        else
            cout << p[0][i];
    }
    cout << endl;
  //  cout << "maxCap : " << mCapacity << endl;
    mCapacity--;
    if(pas%mCapacity == 0)
        trip = pas/mCapacity;
    else
        trip = pas/mCapacity + 1 ;

    cout << trip;

  //  tr(p,it) cout << *it << endl;
  //  cout << "cap : \n";
  //  tr(maxCap,it) cout << *it << endl;

 return 0;
 }
