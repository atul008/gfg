 #include <bits/stdc++.h>
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
 bool comp(const int& lhs,const int& rhs){
    return (lhs>rhs);
 }
 int main(){
    int arr[] = {4,2,7,1,9,3};
    vector<int> v(arr,arr+6);
    make_heap(all(v),comp);
    cout << v.front() << endl;
    sort_heap(all(v),comp);
    tr(v,i) cout << *i << " ";
    cout << endl;

 return 0;
 }
