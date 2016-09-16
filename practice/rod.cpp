#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int rod(int *price ,int n){
    int val[n+1];
    val[0] = 0;

    for(int len = 1; len <= n;len++){
        int maxval = INT_MIN;
        for(int cut = 0;cut < len ;cut++){
           maxval = max(maxval, price[cut] + val[len-cut-1]);
        }
        val[len] = maxval;
    }
    return val[n];
}


int main(){

int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
int n = sizeof(price)/sizeof(price[0]);
cout << "Max Profit: " << rod(price,n) << endl;
return 0;
}
