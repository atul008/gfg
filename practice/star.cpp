#include <iostream>
using namespace std;

int main(){
    string str = "*****";
    cout << str << endl;
    for(int i=0;i<5/2;i++){
        str[i] = ' ';
        str[4-i] = ' ';
        cout << str << endl;
    }
    return 0;
}
