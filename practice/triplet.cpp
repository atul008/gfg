#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void display(deque<int>& ll){
	deque<int>::iterator it;

	for(it = ll.begin(); it != ll.end() ;it++){
		cout << *it << " " ;
	
	}
	cout << endl;
}

void findTriplet(deque<int>& ll1,deque<int>& ll2,deque<int>& ll3,int k){
	int sum = 0 ;
	deque<int>::iterator it1,it2,it3;

	for(it1 = ll1.begin(); it1 != ll1.end() ;it1++){
	
		for(it2 = ll2.begin(),it3 = ll3.begin(); it2 != ll2.end() && it3 != ll3.end(); ){
			
			sum = *it1 + *it2 + *it3 ;
			if(sum == k){
				cout << "Triplet found : " << *it1 << " " << *it2 << " " << *it3 << endl ; 
				return ;
			}
			if(sum < k)
				it2++;
			if(sum > k)
				it3++;			
		}

	}
	cout << "Triplet not found \n" ;
}


int main(){
	
	deque<int> ll1,ll2,ll3;
	deque<int>::iterator it;
	ll1.push_back(10);
	ll1.push_back(20);
	ll1.push_back(30);
	
	ll2.push_back(55);
	ll2.push_back(33);
	ll2.push_back(11);
	
	ll3.push_back(30);
	ll3.push_back(70);
	ll3.push_back(5);
	
	display(ll1);
	display(ll2);
	display(ll3);
	
	sort(ll1.begin(),ll1.end());
	sort(ll2.begin(),ll2.end());
	sort(ll3.rbegin(),ll3.rend());
	
	display(ll1);
	display(ll2);
	display(ll3);
	findTriplet(ll1,ll2,ll3,85);
	
return 0;
}
