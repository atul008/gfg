#include <bits/stdc++.h>
using namespace std;
#define FOR(a,b,i) for(int i=a;i<=b;i++)
#define left(i) (2*i)
#define right(i) (2*i + 1)
void heapify(int *arr,int& hs,int i){
    int m,l = left(i), r = right(i);
    if(l <= hs && arr[l] < arr[i])
        m = l;
    else
        m = i;
    if(r <=hs && arr[r] < arr[m])
        m = r;
    if(i != m){
        swap(arr[m],arr[i]);
        heapify(arr,hs,m);
    }
}

void buildHeap(int *arr,int& hs,int n){
    hs = n;
    for(int i = (n/2) + 1; i>=1;i--)
        heapify(arr,hs,i);
}

int extractMin(int *arr,int& hs){
    int m = arr[1];
    arr[1] = arr[hs];
    hs--;
    heapify(arr,hs,1);
    return m;
}

void decreaseKey(int *arr,int i,int k){
    arr[i] = k;
    while(i>=1 && arr[i/2] > arr[i]){
        swap(arr[i],arr[i/2]);
        i = i/2;
    }
}

void insert(int *arr,int& hs,int k){
    hs++;
    arr[hs] = INT_MAX;
    decreaseKey(arr,hs,k);
}


int main(){
    int arr[] = {-1,4,3,2,6};
    int n = sizeof(arr)/sizeof(arr[0]) - 1;
    int hs = 0;
    buildHeap(arr,hs,n);
   // FOR(1,n,i) cout << arr[i] << " ";
    //cout << endl;
    int a,b;
    int res = 0;
    while(hs > 1){
       // FOR(1,hs,i) cout << arr[i] << " ";
        //cout << endl;
        a = extractMin(arr,hs);
       // FOR(1,hs,i) cout << arr[i] << " ";
      //  cout << endl;
        b = extractMin(arr,hs);

     //   cout << "a: " << a << " b: " << b << endl;
        res =res + a + b;
        insert(arr,hs,a+b);
    }
    cout << res << endl;

}
