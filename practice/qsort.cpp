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

 int partition(vi& v,int l,int h){
    int x = v[h];
    int i = l-1;
    repA2B(l,h-1,j){
        if(v[j] <= x){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
 return i+1;
 }

 void qsort(vi& v,int l,int h){
    if(l<h){
        int p = partition(v,l,h);
        qsort(v,l,p-1);
        qsort(v,p+1,h);
    }
 }

 int main(){
    int arr[] = {6,5,2,4,1,9,3,10};
    vi v(arr,arr+8);
    qsort(v,0,v.size()-1);
    rep(v.size(),i) cout << v[i] << " ";
    cout << endl ;
 return 0;
 }

