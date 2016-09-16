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
 bool isPalin(string str){
    int l = str.length();
    cout << " Length : " << l << endl;
    int j = l-1;
    int i = 0;
    while(i<j){
        if(str[i] != ' ' && str[j] != ' ' && str[i] != str[j] ) return false;
        if(str[i] == str[j]) {
            i++;
            j--;
        }
        if(str[i] == ' ') i++;
        if(str[j] == ' ') j--;
    }
    return true;
 }

 int main(){
 string str("race   car");
 cout << "Is str palindrome : " << isPalin(str) << endl;
 return 0;
 }

