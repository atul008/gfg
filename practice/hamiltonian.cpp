 #include<iostream>
 #include<vector>
 #include<algorithm>
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
 #define rep1(a,i) for(int i =1; i<a; i++)

 #define V 5
 void printSol(const vi& path){
    rep(V,i) cout << path[i] << " " ;
    cout << path[0] <<endl;
 }

 bool isSafe(int graph[V][V],vi& path,int v){

    if(cpresent(path,v))
         return false;

 return true;
 }

 bool util(int graph[V][V],vi& path,int v,int index){
     if(index==V && graph[path[index-1]][path[0]])
     return true;

     rep1(V,i){
        if(graph[path[index-1]][i] && isSafe(graph,path,i)){
            path[index] = i;
            if(util(graph,path,i,index+1)== true)
                return true;
            path[index] = -1;
        }

     }
     return false;
 }

 void hamiltonian(int graph[V][V]){
    vi path(V);

    rep(V,i) path[i] =-1;

    path[0]=0;
    if(util(graph,path,0,1) == true){
        printSol(path);
    }else{
       cout << "Solution does't exists\n";
    }
 }

 int main(){
 int graph[V][V]= {{1, 1, 0, 1, 0},
                      {1, 1, 1, 1, 1},
                      {0, 1, 1, 0, 1},
                      {1, 1, 0, 1, 1},
                      {0, 1, 1, 1, 1},
            };
 hamiltonian(graph);
 return 0;
 }

