#include<iostream>
#include<vector>
using namespace std;
#define N 4

void print2D(int sol[N][N]){
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout << sol[i][j] << " " ;
        cout << endl;
        }
}

int isSafe(int x,int y,int maze[N][N] ){
    if(x >=0 && x< N && y>=0 && y<N && maze[x][y] == 1)
        return 1;

    return 0;
}

bool util(int x,int y,int sol[N][N],int maze[N][N]){
    if(x == N-1 && y == N-1){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(x,y,maze)){
        sol[x][y] = 1;

    if(util(x+1,y,sol,maze)== true)
        return true;
    if(util(x,y+1,sol,maze)== true)
        return true;

        sol[x][y] = 0;
    return false;
    }

    return false;
}

void solMaze(int maze[N][N]){
    int sol[N][N];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) sol[i][j]=0;

    if(util(0,0,sol,maze)== true)
        print2D(sol);
    else
        cout << "Solution dont exist.\n";
}

int main(){
    int maze[N][N] = { {1,0,0,0},
                       {1,1,0,1},
                       {0,1,0,0},
                       {1,1,1,1}
                        };
solMaze(maze);
return 0;

}

