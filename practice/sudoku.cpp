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

 #define N 9
 void printSol(int solution[N][N]){
    rep(N,i){
         rep(N,j) cout << solution[i][j] << " " ;
         cout << endl;
    }
 }

 bool isSafe(int mat[N][N],int row,int col,int num){
        rep(N,i) if(mat[i][col] == num) return false;
        rep(N,j) if(mat[row][j] == num) return false;
        int segRow,segCol;
        segRow = row/3;
        segCol = col/3;
        segRow *=3;
        segCol *=3;
        rep(3,i) rep(3,j) if(mat[segRow+i][segCol+j] == num) return false;
 return true;
 }

bool findEmpty(int mat[N][N],int* row,int* col){
    rep(N,i) rep(N,j)
        if(mat[i][j] == 0){
            *row = i;
            *col = j;
            return true;
        }
    return false;
}

 bool util(int mat[N][N]){
    int row,col;

    if(!findEmpty(mat,&row,&col))
    return true;

    rep1(10,num){
        if(isSafe(mat,row,col,num)){
            mat[row][col] = num;
            if(util(mat) == true)
                return true;
            mat[row][col] = 0;
        }
    }
 return false;
 }

 void sudoku(int mat[N][N]){
    if(util(mat) == true){
        printSol(mat);
    }else{
       cout << "Solution does't exists\n";
    }
 }

 int main(){
 int mat[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
              {5, 2, 0, 0, 0, 0, 0, 0, 0},
              {0, 8, 7, 0, 0, 0, 0, 3, 1},
              {0, 0, 3, 0, 1, 0, 0, 8, 0},
              {9, 0, 0, 8, 6, 3, 0, 0, 5},
              {0, 5, 0, 0, 9, 0, 6, 0, 0},
              {1, 3, 0, 0, 0, 0, 2, 5, 0},
              {0, 0, 0, 0, 0, 0, 0, 7, 4},
              {0, 0, 5, 2, 0, 6, 3, 0, 0}};

 sudoku(mat);
 return 0;
 }


