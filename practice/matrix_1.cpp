#include<iostream>
#include<algorithm>
using namespace std;


int maxMatOne(int mat[6][5],int r ,int c ){
    int s[r][c];

    for(int i = 0;i<r;i++)
        s[i][0] = mat[i][0];

    for(int i = 0;i<c;i++)
        s[0][c] = mat[0][i];

    for(int i =1 ;i< r;i++){
        for(int j =1;j<c;j++){
            if(mat[i][j] == 1)
                s[i][j] = min(s[i-1][j],min(s[i][j-1],s[i-1][j-1])) + 1;
            else
                s[i][j] = 0;

        }
    }
    int max = 0;
    for(int i =0 ;i< r;i++)
        for(int j =0;j<c;j++)
            if(max < s[i][j])
                max = s[i][j];

    return max;
}


int main(){
int mat[6][5]= {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    cout << " Max mat with all one is of size : "<< maxMatOne(mat,6,5) << endl;
return 0;
}
