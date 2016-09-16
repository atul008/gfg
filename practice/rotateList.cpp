#include <iostream>
#include <deque>
using namespace std;
void rotate(int k ,deque<int>& ll){
	cout << "Begin of function\n";
	int data,i = 0;
	deque<int>::iterator it;
	if(k < ll.size()){
		for(it = ll.begin(); i < k  ;i++,it++){
			data = *it;
			ll.pop_front();
			ll.push_back(data);
			//cout << "Poped element : " << data << endl;
		}
	} else {
		cout << "K must be less than linklist size\n";
	
	}
}

int main(){
	
	deque<int> ll;
	deque<int>::iterator it;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.push_back(40);
	ll.push_back(50);
	ll.push_back(60);
	
	for(it = ll.begin(); it != ll.end() ;it++){
		cout << *it << " " ;
	
	}
	cout << endl;

	rotate(3,ll);
	
	for(it = ll.begin(); it != ll.end() ;it++){
		cout << *it << " " ;
	
	}
	cout << endl;	
return 0;
}
