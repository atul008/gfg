#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	deque<int> queue ;
	deque<int>::iterator it; 	
	int page = 0, index = 0 , maxFrames = 4, noOfPages = 0;

	cout << "Enter the page no. to be refrenced \n Enter -1 to quit !! \n";
	cin >> page ;
	
	while(page != -1){
		index = ( find(queue.begin(),queue.end(),page) - queue.begin()); 
		if(index < queue.size()){
			cout << "Page Hit !!\n Index : " << index << endl;
			queue.erase(queue.begin() + index); 
			queue.push_front(page);
		
		} else {
		
			cout << "Page fault\n";
			if(noOfPages < maxFrames){
				queue.push_front(page);
				noOfPages++;
			} else {
				cout << "Queue full .. Replacing page\n";
				queue.pop_back();
				queue.push_front(page);
			}	
		
		}
			
		for(it = queue.begin(); it != queue.end() ;it++){
			cout << *it << " ";
		} 
	
		cout << "\nEnter the page no. to be refrenced \n";
		cin >> page ;		
	}

/*	for(it = deq.begin(); it != deq.end() ;it++){
		cout << *it << " ";
	} 
	
	if(find(deq.begin(),deq.end(),43) != deq.end()){
		cout << "Element found : " << endl;
	} else {
		cout << "Element not found !\n";
	}
	
*/
return 0;
} 

