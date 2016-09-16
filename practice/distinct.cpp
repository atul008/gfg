 #include <set>
 #include <iostream>
 #include <string>
 using namespace std;
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 int main(){
    string str;
    getline(cin,str);
    int len = str.length();
    set<char> s;
    FOR(0,len-1,i){
        if(str[i] >='a' && str[i] <='z')
            s.insert(str[i]);
    }
    cout << s.size() << endl;

 return 0;
 }
