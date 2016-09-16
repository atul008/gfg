#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void uglyUptoCount(int n){
    int i2,i3,i5,minNum;
    vector<int> ugly;

    ugly.push_back(1);
    i2 = i3 = i5 =0;

    for(int count = 1;count <=n; ){
        minNum = min(ugly[i2]*2,min(ugly[i3]*3 ,ugly[i5]*5));

        if(minNum == ugly[i2]*2)
            i2++;
        if(minNum == ugly[i3]*3)
            i3++;
        if(minNum == ugly[i5]*5)
            i5++;

        ugly.push_back(minNum);
        count++;
    }
    vector<int>::iterator it;
    cout << "Ugly number upto " << n << endl;
    for(it = ugly.begin(); it !=ugly.end();it++ )
        cout << *it << endl;
return ;
}


int main(){
    uglyUptoCount(150);
return 0;
}

