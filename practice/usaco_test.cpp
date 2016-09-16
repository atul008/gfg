/*
ID: atulk181
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string cName,gName;
    int cNum = 1 ,gNum = 1;
    fin >> cName >> gName;
  //  cin >> cName >> gName;
    for(int i = 0;i<cName.length();i++){
        int a = cName[i]-'A'+1;
        cNum *= a;
    }
    for(int i = 0;i<gName.length();i++){
        int a = gName[i]-'A'+1;
        gNum *= a;
    }
    if((cNum%47) == (gNum%47))
       fout << "GO\n";
    else
        fout << "STAY\n";

    return 0;
}

