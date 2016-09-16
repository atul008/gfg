#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& count,long long c,long long p,long long* ui,long long* uj){
    long long k2,i2,i=3,j=4,k,n;
    for(k=p;k<=c;k++){
	    k2 = k*k;
        for(i=*ui;i<k;i++){
            i2 = i*i;
            for(j=*uj;j<k;j++){
                if(i2+(j*j) == k2){
                    count[k] = count[k-1]+1;
                    *ui = i;
                    *uj = j;
                }
            }
        }
        if(count[k]==0) count[k] = count[k-1];
     //  cout << "k : " << k << " count : " << count[k] << endl;
	}
}

int main()
{
	long long t,c,p,ui=3,uj=4;
	vector<int> count(1000002,0);
    cin >> t;
    p=0;
  //  solve(count,100,5);
	while(t--){
        cin >> c;
        if(c>p){
            solve(count,c,p,&ui,&uj);
            p=c;
        }
		cout << count[c] << endl;
	}
	return 0;
}

