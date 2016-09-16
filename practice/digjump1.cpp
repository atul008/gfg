 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cstring>
 #include <climits>
 #include <stack>
 #include <queue>
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

 void makeGraph(vvi& graph,string& s,vi& v){
    int i1,i2;
    v[s[0]-'0'] = 1;
    i2 = s[0]-'0';
    repA2B(1,s.length()-1,i){
        i1 = s[i]-'0';

        if(v[i1] == 1)
            i1 += 10;
        v[i1] = 1;

        graph[i1][i2] = 1;
        graph[i2][i1] = 1;
        i2 = i1;
    }
    repA2B(0,9,i)
        if(v[i] == 1 && v[i+10] == 1){
            graph[i][i+10] = 1;
            graph[i+10][i] = 1;
        }
 }

 int findShortest(vvi& graph,int src,int dest,int n){
    queue<int> q;
    vi vis(20,0);
    vi dist(20,-1);
    vi::iterator it;
    int neigh;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;
    neigh = src;
    while(!q.empty()){
      int curr = q.front();
      q.pop();
      int currLen = dist[curr];
      if(curr == dest){
      return currLen;
      //  rep(20,i) cout << dist[i] << " ";
     //   cout << endl;


       // cout << "n : " << n << " neigh : " << neigh << endl;
       /* if((n != neigh  || dest-10 == neigh))
            return currLen;
        else
           return currLen+1;
      */
      }

      rep(20,i){
            if(graph[curr][i] && !vis[i] ){
                vis[i] = 1;
                q.push(i);
                dist[i] = currLen + 1;
                if(i == dest) neigh = curr;
            }
      }
    }

    return -1;
 }


 int main(){

    string s;
    cin >> s;
    int len = s.length();
    vvi graph(20,vi(20,0));
    vi v(20,0);

  if(len <= 1){
    cout << "0" << endl;
    return 0;
  }else if(len == 2){
    cout << "1" << endl;
  }else{
      makeGraph(graph,s,v);
  /*    rep(20,i){
        rep(20,j){
        cout << graph[i][j] << " " ;
        }
        cout << endl;
      }

      cout << "v : " << endl;
      rep(20,i) cout << v[i] << " ";
      cout << endl;
*/
      int src = s[0]-'0';
      int dest = s[len-1]-'0';
      int n = s[len-2]-'0';
      if(v[dest+10] == 1) dest += 10;
      if(v[n+10] == 1) n += 10;
   //   cout << src << " " << dest << endl;
     int ans = findShortest(graph,src,dest,n);
        cout << ans << endl;
 }
 return 0;
 }
