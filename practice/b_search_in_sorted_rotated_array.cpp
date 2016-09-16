 #include<iostream>
 #include<algorithm>
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
 #define rep1(a,i) for(int i=1; i<a ;i++)
 #define repA2B(a,b,i) for(int i=a; i<=b; i++)

int findPivot(vi& arr,int l,int h){
    if(l>h) return -1;
    if(l==h) return l;
    int mid=(l+h)/2;
    if(mid < h && arr[mid] > arr[mid+1]) return mid;
    if(mid > l && arr[mid] < arr[mid-1]) return mid-1;

    if(arr[mid] <= arr[l])
     findPivot(arr,l,mid-1);
    else
     findPivot(arr,mid+1,h);
}

int bSearch(vi& arr,int l,int h,int n){
    if(l<h){
        int mid = (l+h)/2;
        if(n==arr[mid])
            return mid;
        else if(n<arr[mid])
            bSearch(arr,l,mid-1,n);
        else
            bSearch(arr,mid+1,h,n);
    }
    else
        return -1;
}

int pivotedBSearch(vi& arr,int n){
    int pivot = findPivot(arr,0,sz(arr)-1);
    if(pivot==-1)
        return bSearch(arr,0,sz(arr)-1,n);
 //   cout << "pivot : ";
   // cout  << pivot << endl;
    if(n == arr[pivot])
      return pivot;
    else if(n >= arr[0])
      return bSearch(arr,0,pivot-1,n);
    else
      return bSearch(arr,pivot+1,sz(arr)-1,n);

}

int main(){
    int arr[]= {5,6,7,1,2,3,4};
    vi v(arr,arr+7);
    int index = pivotedBSearch(v,7);
    cout << "Search result : " << index << endl;
    return 0;
}
