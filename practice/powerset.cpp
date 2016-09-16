#include <iostream>
using namespace std;
int main(){
    char set[5] = { 'a','b','c','d','e' };
    int setSize = 1 << 5;
    for(int i = 0;i< setSize;i++){
        for(int j=0;j<5;j++){
            if((i>>j) & 1)
                cout << set[j] << " ";
        }
        cout << endl;
    }
return 0;
}
