 #include<iostream>
 #include<vector>
 #include<set>
 #include<algorithm>

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

 void print(const vi& tuple){
     cout << "subset : size :  " << tuple.size() << endl ;
    tr(tuple,it)
        cout << *it << " " ;
    cout << endl;
 }

 void subsetSum(vi& s,vi& tuple,int sum ,int index ,int const t_sum){
    int x;
    if(sum == t_sum){
        print(tuple);
        tuple.pop_back();
        if(index+1 < s.size() && sum-s[index]+s[index+1] <= t_sum){
            subsetSum(s,tuple,sum-s[index],index+1,t_sum);
        }
        return;

    } else {
        if(index < s.size() && sum + s[index] <= t_sum ){

            for(int i=index;i < s.size();i++){
                tuple.push_back(s[i]);
                if(sum + s[i] <= t_sum){
                    subsetSum(s,tuple,sum+s[i],i+1,t_sum);
                }
                if(tuple.size()>=1)
                 tuple.pop_back();
            }
        }
    }
 }

 void generateSubsetsum(vi& s,int const t_sum){
    sort(all(s));
 //   int total = accumulate(all(s),0);
   int total = 0;
   tr(s,i)
        total+=*i;
    cout << "total : " << total << endl;

    vi tuple;
    if(t_sum >= s[0] && t_sum <= total){
        subsetSum(s,tuple,0,0,t_sum);
    }
 }

 int main(){
 int arr[] = {15, 22, 14, 26, 32, 9, 16, 8};
 vi v(arr,arr+8);
 generateSubsetsum(v,53);
 return 0;
 }

