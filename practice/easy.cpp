 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 void bSearch(vi& arr,int l,int h,int n,int& index){
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
    int n,q,x,y,a,inver;
    cin >> n >> q;
    vi arr;
    arr.pb(-1);
    FOR(1,n,i) {
        cin >> a;
        arr.pb(a);
    }
    cin >> x >> y;
    while(q--){
        inver = 0;
        swap(arr[x],arr[y]);
        vi b(all(arr)),a(all(arr));
        sort(all(b));
        while(sz(b) > 2){
            int e = a[1];
            int index = 0;
            bSearch(b,1,b.size()-1,e,index);
            inver += (index-1);
            vi::iterator it = find(all(b),e);
            b.erase(it);
            a.erase(++(a.begin()));
  /*          cout << inver << endl;
            tr(a,iit) cout << *iit << " ";
            cout << endl;

            tr(b,iit) cout << *iit << " ";
            cout << endl;
*/
        }
        cout << inver%2 << endl;
    }
 return 0;
 }
