#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void pairLis(vector<pair <int,int> > v){

    vector<pair <int,int> >::iterator it;
    int count =1;

    for(it = v.begin();it != v.end();it++){
        cout << it->first <<" "<< it->second << endl;
    }

    sort(v.begin(),v.end());

    for(it = v.begin();it != v.end();it++){
        cout << it->first <<" "<<it->second << endl;
    }

    for(it = v.begin();it != v.end();it++){
        if(it->second < (it+1)->first)
            count++;
    }
    cout << "Count : " << count << endl;


}

int main(){

    vector<pair <int ,int > > v(4);
    v[0].first = 5;
    v[0].second = 24;

     v[1].first = 15;
    v[1].second = 25;

     v[2].first = 27;
    v[2].second = 40;

     v[3].first = 50;
    v[3].second = 60;

   pairLis(v);
  return 0;

}

