#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(){

    string s("this is a string");
    stringstream ss(s);
    vector<string> v;
    vector<string>::iterator it;
    string str;
    while(getline(ss,str,' '))
        v.push_back(str);

    for(it=v.begin();it!=v.end();it++)
        cout << *it << endl;


return 0;
}
