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

int isSafe(int x,int y,int sol[N][N] ){
    if(x >=0 && x< N && y>=0 && y<N && sol[x][y] == -1)
        return 1;

    return 0;
}

int util(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N]){
        if(movei == N*N) return true;
        int curr_x=0,curr_y=0;

        for(int k =0;k<8;k++){
            curr_x = x + xMove[k];
            curr_y = y + yMove[k];

            if(isSafe(curr_x,curr_y,sol)){
                sol[curr_x][curr_y]= movei;
                if(util(curr_x,curr_y,movei+1,sol,xMove,yMove) == true)
                    return true;
                else
                    sol[curr_x][curr_y] = -1;
            }
        }

    return false;
}

bool solKTP(){
    int sol[N][N];

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) sol[i][j] = -1;

    int xMove[8] = {2,1,-1,-2,-2,-1,1,2};
    int yMove[8] = {1,2,2,1,-1,-2,-2,-1};

    sol[0][0] = 0;

    if(util(0,0,1,sol,xMove,yMove) == false){ cout << "Sol dont exists\n"; return false; }
    else print2D(sol);

    return true;
}

int main(){
solKTP();
return 0;

}

