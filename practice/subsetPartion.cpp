#include<iostream>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
bool isSubsetSum(int *arr,int n,int sum){
  /*  if(sum == 0)
        return true;

    if(n == 0 && sum !=0)
        return false;
   */

   bool part[sum+1][n+1];
    for(int i =0 ;i<=sum;i++)
        part[0][i] = true;

    for(int i =1 ;i<=n;i++)
        part[i][0] = false;

    for(int i = 1;i<=sum;i++){
        for(int j = 1;j<=n;j++){
            if(i >= arr[j-1])
                part[i][j] = part[i][j-1] || part[i-arr[j-1]][j-1];
            else
                part[i][j] = part[i][j-1];
        }
    }

    return part[sum][n];
}

bool  partion(int *arr,int n){

    int sum = 0;

    for(int i =0 ;i<n;i++)
        sum += arr[i];

    if(sum % 2 == 1)
        return false;
    else{
        return isSubsetSum(arr,n,sum/2);
    }
}

int main(){

    int arr[] = {3,1,1,2,2,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Is Partioning possible ? : " << partion(arr,n) << endl;
return 0;
}
