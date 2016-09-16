 #include<iostream>
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

 #define V 4
 void printSol(int color[]){
    rep(V,i) cout << color[i] << " " << endl;
    cout << endl;
 }

 bool isSafe(int graph[V][V],int color[],int v,int c ){

    rep(V,i){
        if(graph[i][v] == 1 && c == color[i])
         return false;
    }
 return true;
 }

 bool util(int graph[V][V],int color[],int m,int v){

    if(v==V)
        return true;

    for(int c = 1;c<=m; c++){
        if(isSafe(graph,color,v,c)){
            color[v] = c;
            if(util(graph,color,m,v+1) == true)
                return true;

            color[v] = 0;
        }
    }
    return false;
 }

 void mColor(int graph[V][V],int m){
    int color[V];

    rep(V,i) color[i] =0;

    if(util(graph,color,m,0) == true){
        printSol(color);
    }else{
       cout << "Solution does't exists\n";
    }
 }

 int main(){
 int graph[V][V]= {{1, 1, 1, 1},
            {1, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 0, 1, 1},
            };
 mColor(graph,3);
 return 0;
 }

