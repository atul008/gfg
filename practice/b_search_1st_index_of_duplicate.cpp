#include<iostream>
using namespace std;

void bSearch(int arr[],int l,int h,int n,int& index){
    if(l<h){
        int mid = (l+h)/2;
        if(n == arr[mid]){
            index = mid;
            bSearch(arr,l,mid,n,index);
        }
        else if(n < arr[mid])
            bSearch(arr,l,mid,n,index);
        else
            bSearch(arr,mid+1,h,n,index);

    }
}

int main(){
    int arr[] = {1,2,2,2,2,3,3,3,3,3,7,7,7,7,7,7,9,9,9,9};
    int index = -1;
    bSearch(arr,0,19,20,index);
    cout<< index<< endl;
return 0;
}


