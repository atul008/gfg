 #include<iostream>
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

 void makeGraph(vvi& graph,string& s){
    //rep(10,i) graph[i][i] = 1;
    repA2B(1,s.length()-1,i){
        graph[s[i]-'0'][s[i-1]-'0'] = 1;
        graph[s[i-1]-'0'][s[i]-'0'] = 1;
    }
 }

 int findSortest(vvi& graph,int src,int dest){
    queue<int> q;
    vi vis(10,0);
    vi dist(10,-1);
    vi::iterator it;

    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while(!q.empty()){
      int curr = q.front();
      q.pop();
      int currLen = dist[curr];
      if(curr == dest) return currLen;

      rep(10,i){
            if(graph[curr][i] && !vis[i] ){
                vis[i] = 1;
                q.push(i);
                dist[i] = currLen + 1;
            }
            if(graph[curr][curr]) dist[i]++;
      }
    }
   /* rep(10,i){
        cout << dist[i] << " ";
    }
    cout << endl;
*/
    return dist[dest];
 }


 int main(){
    string s;
    cin >> s;
    int len = s.length();
    vvi graph(10,vi(10,0));
    makeGraph(graph,s);

    rep(10,i){
        rep(10,j){
        cout << graph[i][j] << " " ;
        }
        cout << endl;
    }
  int src = s[0]-'0';
    int dest = s[len-1]-'0';
  //  cout << src << " " << dest << endl;
   if(len == 1)
    cout << "0\n";
   else if(src == dest)
    cout << "1\n";
   else
    cout << findSortest(graph,src,dest) << endl;

 return 0;
 }
