#include<iostream>
#include<vector>
using namespace std;
#define N 8

void print2D(int sol[N][N]){
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout << sol[i][j] << " " ;
        cout << endl;
        }
}

int isSafe(int row,int col,int board[N][N] ){

    for(int j=col;j>=0;j--){
        if(board[row][j]==true)
            return false;
    }

    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j] ==true)
            return false;
    }
    for(int i=row,j=col;i < N && j >=0 ;i++,j--){
        if(board[i][j] ==true)
            return false;
    }

    return true;
}

bool util(int col,int board[N][N]){
        if(col >= N){
            return true;
        }
    for(int i=0;i<N;i++){
        if(isSafe(i,col,board)){
            board[i][col] = 1;
            if(util(col+1,board) == true)
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}

void solNQueen(){
    int board[N][N];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) board[i][j] = 0;

    if(util(0,board) == true)
        print2D(board);
    else
        cout << "Solution dont exists.\n";

}

int main(){
solNQueen();
return 0;

}


